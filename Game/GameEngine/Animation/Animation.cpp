//
// Created by chauvin on 22/01/18.
//

#include "Animation.hpp"
#include "../Sprite/Sprite.hpp"

namespace TacosEngine {
    Animation::Animation(const std::string &myname, const std::shared_ptr<GameObject> &gameObject, bool loop,
                         int frame_speed, const std::vector<TacosEngine::ITexture *> &frames) : Component(myname,
                                                                                                          gameObject),
                                                                                                _loop(loop),
                                                                                                _frame_speed(
                                                                                                        frame_speed),
                                                                                                _frames(frames){
        _frame = 0;
        _check_speed = 0;
    }

    void Animation::update(int tick) {

        std::shared_ptr<Sprite> sp = std::dynamic_pointer_cast<Sprite>(_object);

        if (!this->_loop && _frame >= this->_frames.size() - 1) {
            this->setActive(false);
            return;
        }
        if (this->_frame <= this->_frames.size() && (_check_speed) >= _frame_speed) {
            _frame++;
            _check_speed = 0;
        }
        if (_frame > this->_frames.size() - 1 && this->_loop) {
            _frame = 0;
            _check_speed = 0;
        }
        _check_speed++;
        if (sp->getTexture() != this->_frames[_frame]) {
            sp->setTexture(this->_frames[_frame]);
        }
    }

    bool Animation::is_loop() const {
        return _loop;
    }

    void Animation::set_loop(bool _loop) {
        Animation::_loop = _loop;
    }

    int Animation::get_frame_speed() const {
        return _frame_speed;
    }

    void Animation::set_frame_speed(int _frame_speed) {
        Animation::_frame_speed = _frame_speed;
    }

    const std::vector<TacosEngine::ITexture *> &Animation::get_frames() const {
        return _frames;
    }

    void Animation::set_frames(const std::vector<TacosEngine::ITexture *> &_frames) {
        Animation::_frames = _frames;
    }

    int Animation::get_frame() const {
        return _frame;
    }

    void Animation::set_frame(unsigned int _frame) {
        Animation::_frame = _frame;
    }
}
