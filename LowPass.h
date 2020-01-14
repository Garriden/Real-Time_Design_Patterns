class LowPass {

	public:
		LowPass();
		LowPass(Pipe& in, Pipe& out);

		~LowPass();

		Pipe* pipe_input;
		Pipe* pipe_output;
		Event::Type pass_value;
		int run();
}
