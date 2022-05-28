#include <Console3D/Console3D.h>

class MyApp : public Console3D::App {

};

int main() {
    Console3D::Space::reserveMemory(1);
    std::shared_ptr<Console3D::Object::Sphere> sphere = std::make_shared<Console3D::Object::Sphere>(Console3D::Vector3d(30, 12, 3), 3);
    std::shared_ptr<Console3D::Object::Sphere> sphere2 = std::make_shared<Console3D::Object::Sphere>(Console3D::Vector3d(60, 20, 5), 3);
    Console3D::Space::addObject(sphere);
    Console3D::Space::addObject(sphere2);

    std::unique_ptr<MyApp> app = std::make_unique<MyApp>();
    app->createNewCamera(100, 25);
    app->Begin();
    while (app->IsRunning()) {
        app->Update();

        if (GetKeyState(VK_SPACE)) app->End();
    }

    system("pause");

    return 0;
}