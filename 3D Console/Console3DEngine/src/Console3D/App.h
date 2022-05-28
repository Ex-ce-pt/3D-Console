#pragma once

#include <c3dpch.h>

#include "Camera.h"
#include "Renderer.h"

namespace Console3D {

	class App {
	protected:

		class AppRenderer : public Renderer {
		public:
			AppRenderer() = default;

			void render() override;
		};

	protected:
		using CameraPtr = std::shared_ptr<Camera>;

		std::unique_ptr<AppRenderer> renderer;
		CameraPtr mainCamera;
		bool running;

	public:
		App();

		virtual void Begin();
		virtual void Update();
		virtual void End();

		bool IsRunning() const;

		CameraPtr createNewCamera(type::c_uint _w, type::c_uint _h);
		void setMainCamera(Camera* camera);
		CameraPtr getMainCamera() const;
	};

}