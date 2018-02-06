/*
namespace TacosEngine
{
    class Behaviour;

    class PlayerBehaviour : public Behaviour {
    private:
        float sizeX;
        float sizeY;

    public:
        PlayerBehaviour(const std::string &name, std::shared_ptr<GameObject> object)
                : Behaviour(name, std::move(object)) {
        }

        ~PlayerBehaviour() override = default;

        void Start() override {
            std::cout << "In Start()" << std::endl;
            auto sp = std::dynamic_pointer_cast<Sprite>(_object);
            sizeX = sp->getSize().get_x();
            sizeY = sp->getSize().get_y();
            _object->getTransform().setSpeed(4.0f);
        }

        void update(const Input &input) override {
            Vector2 dir(input.getAxis("Horizontal"), input.getAxis("Vertical"));
            auto rb = getComponent<Rigidbody>();

            if (input.getAxis("Horizontal") != 0 && input.getAxis("Vertical") != 0)
                dir = dir / 2;
            CheckWindowCollide(dir);
            _object->getTransform().setDirection(dir);
            rb->addForce(dir * _object->getTransform().getSpeed());
        }

        void onCollide(GameObject &other) override {
            std::cout << "OnCollide() => " << other.getInstanceName() << std::endl;
            if (other.getInstanceName() == "Obs") {
                if (auto obs2 = _object->findByName("Obs2"))
                    obs2->getTransform().setPosition(Vector2(10, 10));
                setDestroy(true);
            }
        }

        Vector2    &CheckWindowCollide(Vector2 &dir)
        {
            if (dir.get_x() < 0 && _object->getTransform().getPosition().get_x() <= 0.5 ||
                dir.get_x() > 0 && _object->getTransform().getPosition().get_x() >= (799.5 - sizeX))
                dir.set_x(0);
            if (dir.get_y() > 0 && _object->getTransform().getPosition().get_y() >= (399.5 - sizeY) ||
                dir.get_y() < 0 && _object->getTransform().getPosition().get_y() <= 0.5)
                dir.set_y(0);
            return dir;
        }
    };

    class TextBehaviour : public Behaviour {
    public:
        TextBehaviour(const std::string &name, std::shared_ptr<GameObject> object)
                : Behaviour(name, std::move(object)) {
        }

        ~TextBehaviour() override = default;

        void Start() override {
            std::cout << "In Start()" << std::endl;
            auto rb = getComponent<Rigidbody>();

            rb->addForce(Vector2(0, -1));
        }

        void update(const Input &input) override {
            if (_object->getTransform().getPosition().get_y() < -80)
            {
                std::cout << "New Scene !" << std::endl;
                _object->getScene()->loadNewScene("Scene1");
            }
        }
    };
}

using namespace TacosEngine;

int main()
{
    Engine engine;
    std::shared_ptr<Scene> splashScreen = std::make_shared<Scene>("SplashScreen");
    std::shared_ptr <Scene> scene = std::make_shared<Scene>("Scene1");

    engine.initRessources("ressources.txt");

    // Scene
    engine.addScene(splashScreen);
    engine.addScene(scene);

    // SplashScreen
    std::shared_ptr<Text> rtypeText = std::make_shared<Text>("RtypeText", splashScreen, Layout::UI, Tag::UNKNOWN, "R-Type");
    rtypeText->setColor(Color::YELLOW);
    rtypeText->setFont(scene->getFont("rtypefont"));
    rtypeText->setSize(Vector2(30, 0));
    rtypeText->getTransform().setPosition(Vector2(350, 400));
    std::shared_ptr<TextBehaviour> textBeha = std::make_shared<TextBehaviour>("TextBeha", rtypeText);
    std::shared_ptr<Rigidbody> rigText = std::make_shared<Rigidbody>("RbText", rtypeText);
    splashScreen->addGameObject(rtypeText);
    splashScreen->addComponent(textBeha);
    splashScreen->addComponent(rigText);

    // Sprite background
    std::shared_ptr<Sprite> back = std::make_shared<Sprite>("Background", scene, Layout::BACKGROUND);
    back->setTexture(scene->getTexture("back"));
    back->setSize(Vector2(800, 400));
    scene->addGameObject(back);

    // Sprite ship
    std::shared_ptr <Sprite> player = std::make_shared<Sprite>("Player", scene, Layout::SCENE);
    player->setTexture(scene->getTexture("ship"));
    player->setSize(Vector2(20, 20));
    std::shared_ptr<PlayerBehaviour> playerBeha = std::make_shared<PlayerBehaviour>("playerBeh", player);
    std::shared_ptr<Collider> coll = std::make_shared<Collider>("ok", player, Vector2(20, 20), player->getTransform().getPosition(), true);
    std::shared_ptr<Rigidbody> rig = std::make_shared<Rigidbody>("Rb", player);
    scene->addGameObject(player);
    scene->addComponent(playerBeha);
    scene->addComponent(coll);
    scene->addComponent(rig);

    // Sprite obstacle
    std::shared_ptr <Sprite> obs = std::make_shared<Sprite>("Obs", scene, Layout::SCENE);
    obs->setTexture(scene->getTexture("ship"));
    obs->setSize(Vector2(20, 20));
    obs->getTransform().setPosition(Vector2(400, 200));
    std::shared_ptr<Collider> collObs = std::make_shared<Collider>("Collider", obs, obs->getSize(), obs->getTransform().getPosition(), false);
    std::shared_ptr<Rigidbody> rigObs = std::make_shared<Rigidbody>("Rigidbody", obs);
    scene->addGameObject(obs);
    scene->addComponent(collObs);
    scene->addComponent(rigObs);

    // Sprite obstacle 2
    std::shared_ptr <Sprite> obs2 = std::make_shared<Sprite>("Obs2", scene, Layout::SCENE);
    obs2->setTexture(scene->getTexture("ship"));
    obs2->setSize(Vector2(20, 20));
    obs2->getTransform().setPosition(Vector2(400, 100));
    std::shared_ptr<Collider> collObs2 = std::make_shared<Collider>("Collider", obs2, obs2->getSize(), obs2->getTransform().getPosition(), true);
    std::shared_ptr<Rigidbody> rigObs2 = std::make_shared<Rigidbody>("Rigidbody", obs2);
    scene->addGameObject(obs2);
    scene->addComponent(collObs2);
    scene->addComponent(rigObs2);

    // Load and run scene
    engine.loadScene(splashScreen);
    engine.run();
    return 0;
}*/