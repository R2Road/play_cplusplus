#pragma once

namespace r2
{
	class Camera;

	class iRenderable
	{
	public:
		virtual void Draw( const r2::Camera* const camera ) = 0;
	};
}