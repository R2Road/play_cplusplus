namespace play_cpp_class_private_inheritance_helper___virtual_interface
{
	// private 상속이어도 자식 class 에서 열어 버릴 수 있다.

	class iVirtualPrivate
	{
	private:
		virtual void DoProcess() {};
	};

	class VP_Private : private iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class VP_Protected : protected iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};

	class VP_Public : public iVirtualPrivate
	{
	public:
		void DoProcess() override {}
	};
}