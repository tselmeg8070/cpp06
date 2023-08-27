#ifndef DATA_HPP
# define DATA_HPP

class Data {
	private:
		int	_time;
	public:
		Data();
		Data(int time);
		Data(Data &t);
		~Data();
		Data & operator=(const Data &t);

		int		getTime() const;
		void	setTime(int time);
};

#endif
