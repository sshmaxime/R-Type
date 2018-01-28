//
// Created by sshsupreme on 20/01/18.
//

#include "SNetwork.h"
#include "../Global/Global.h"

std::mutex mutex_AllMessagesReceived;

int SNetwork::Initialize(int port, std::shared_ptr<std::list<std::string>> &allMessageReceived)
{
  _AllMessagesReceived = allMessageReceived;

  Global::Instance()->_Service = new boost::asio::io_service();

    try {
	Global::Instance()->_Socket = new udp::socket(*Global::Instance()->_Service, udp::endpoint(udp::v4(), port));

        this->Receive();
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return 0;
}

int                 SNetwork::Receive()
{
    try {
	Global::Instance()->_Socket->async_receive_from(
                boost::asio::buffer(_DATA), _Endpoint,
                boost::bind(&SNetwork::handleReceive, this,
                            boost::asio::placeholders::error,
                            boost::asio::placeholders::bytes_transferred));
    } catch (std::exception& exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return (0);
}

int                 SNetwork::Send(JSONObject &toSend)
{
    return 0;
}

int                 SNetwork::Run()
{
    try {
	Global::Instance()->_Service->run();
    } catch (std::exception &exception) {
        std::cout << exception.what() << std::endl;
        return (-1);
    }
    return (0);
}

int SNetwork::Shutdown()
{
  Global::Instance()->_Service->stop();
  return 0;
}


bool                isValid(const std::string& str)
{
    return (true);
}

void                SNetwork::handleReceive(const boost::system::error_code &error, size_t bytes)
{
    std::string     msgSender = "[" + _Endpoint.address().to_string() + ":" + std::to_string(_Endpoint.port()) + "]";

    std::cout << "receive" << std::endl;

    _DATA.at(bytes) = '\0';
    if (Global::Instance()->quit)
    {
    	this->Shutdown();
        return;
    }
    this->Receive();
    if (!isValid(std::string(_DATA.c_array())))
        return ;
    mutex_AllMessagesReceived.lock();
    _AllMessagesReceived->push_back(msgSender + std::string(_DATA.c_array()));
    mutex_AllMessagesReceived.unlock();
    this->Receive();
}

SNetwork::~SNetwork()
{
  delete Global::Instance()->_Socket;
  delete Global::Instance()->_Service;
}