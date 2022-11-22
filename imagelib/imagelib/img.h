#pragma once

#include <vector>
#include <iostream>
#include <fstream>

using std::vector;



	class color {
	private:
		uint8_t r;
		uint8_t g;
		uint8_t b;

	public:
		color(uint8_t red, uint8_t green, uint8_t blue);

		void set_r(uint8_t new_r);
		void set_g(uint8_t new_g);
		void set_b(uint8_t new_b);

		uint8_t get_r();
		uint8_t get_g();
		uint8_t get_b();

	};

	class image {
	private:
		vector<vector<color>> map;
		unsigned int m_width;
		unsigned int m_height;

	public:
		image(unsigned int width, unsigned int height, color fill);

		unsigned int get_width();
		unsigned int get_height();
		bool save_ppm(std::string path);
		vector<vector<color>> get_map();
		void set_map(vector<vector<color>> in);
	};
