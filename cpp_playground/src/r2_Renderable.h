#pragma once

namespace r2
{
	class Camera;

	class Renderable
	{
	public:
		virtual void Draw( const r2::Camera* const camera ) = 0;
	};
}