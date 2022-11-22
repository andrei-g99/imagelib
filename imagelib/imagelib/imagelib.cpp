// imagelib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "img.h"



// TODO: This is an example of a library function


	/*  COLOR CLASS DEFINITIONS  */
	color::color(uint8_t red, uint8_t green, uint8_t blue) {
		r = red;
		g = green;
		b = blue;

	}

	void color::set_r(uint8_t new_r) {
		r = new_r;
	}

	void color::set_g(uint8_t new_g) {
		g = new_g;
	}

	void color::set_b(uint8_t new_b) {
		b = new_b;
	}

	uint8_t color::get_r() {
		return r;
	}

	uint8_t color::get_g() {
		return g;
	}

	uint8_t color::get_b() {
		return b;
	}

	/*  IMAGE CLASS DEFINITIONS  */

	image::image(unsigned int width, unsigned int height, color fill) {
		m_width = width;
		m_height = height;
		//filled background image constructor
		for (int i = 0; i < (int)height; i++) {
			vector<color> temp_row;
			for (int j = 0; j < (int)width; j++) {
				temp_row.push_back(fill);
			}
			map.push_back(temp_row);
			temp_row.clear();
		}
	}

	unsigned int image::get_width() {
		return m_width;
	}
	unsigned int image::get_height() {
		return m_height;
	}

	bool image::save_ppm(std::string name) {
		//saves image as PPM file at the specified path dir, returns false if failed
		std::string temp;
		temp = name + ".ppm";
		std::fstream fs;
		fs.open(temp, std::fstream::out);
		if (fs.is_open()) {
			fs << "P6\n";
			fs << m_width << " " << m_height << "\n";
			fs <<255<<"\n";

			//write pixel map
			for (auto& y : map) {
				for (auto& x : y) {
					fs << (char)x.get_g() << (char)x.get_b() << (char)x.get_r();
				}
			}

		}
		else {
			std::cout << temp << " couldn't be created.\n";
			return false;
		}

		fs.close();

		return true;
	}


	vector<vector<color>> image::get_map() {
		return map;
	}

	void image::set_map(vector<vector<color>> in) {
		map = in;
	}
