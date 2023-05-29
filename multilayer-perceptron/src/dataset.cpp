#include "../inc/multilayer-perceptron.hpp"

/*-------------------------------------------------------------------------------*/

dataset::dataset() {

	int             id = 0;
	std::string     line, token;
	std::fstream    stream("data/data.csv");

	init_set();
	if (stream.good()) {

		while(!stream.eof()) {

			std::getline(stream, line);
			process_line(line, id++);
		}
	} else { std::cout << "An error occured while opening the database" << std::endl; }
	// for (int i = 0; i < 569; i++) {
	//     print_id(i);
	// }

	for (int i = 0; i < 570; i++)
	{
		normalize(i);
	}
	//print_set(1);
	//print_norm(1);

	// for (int i = 1; i < 31; i++) {
	//     std::cout << "standard dev[" << i << "] " << _dev[i] << std::endl;
	// }
	// for (int i = 1; i < 31; i++)
	//     std::cout << "mean[" << i << "] " << _mean[i] << std::endl;

}

dataset::~dataset() {}

void dataset::init_set() {

	for (int i = 0; i < 570; i++)
		for (int j = 0; j < 31; j++)
			_set[i][j] = -1.0;
}

void dataset::norm_mean_dev()
{

	for (int feature = 1; feature < 31; feature++) {

		double sum = 0.0;
		for (int line = 0; line < 570; line++)
			sum += _set[line][feature];
		_mean[feature] = sum / 570;
	}

	for (int feature = 1; feature < 31; feature++) {

		double sum = 0.0;
		for (int line = 0; line < 570; line++) {

			double val = _set[line][feature] - _mean[feature];
			sum += val * val;
		}
		_dev[feature] = sqrt(sum / 570 - 1);
	}
}

void dataset::normalize(int id) {

	norm_mean_dev();
	for (int feature = 1; feature < 31; feature++) {

		if (!_dev[feature] || std::isnan(_dev[feature]) || std::isinf(_dev[feature]))
			_norm[id][feature] = _set[id][feature];
		else
			_norm[id][feature] = (_set[id][feature] - _mean[feature]) / _dev[feature];
	}
}

void dataset::print_set(int id) {

	std::ofstream outputFile("output.txt", std::ios::app);

	if (outputFile.is_open()) {

		outputFile << "---------------------------------------         " << "id: " << id << std::endl;
		outputFile << "Diagnosis: " << _set[id][0] << std::endl;
		outputFile << "Mean radius: " << _set[id][static_cast<int>(ft::mean::radius)] << std::endl;
		outputFile << "Mean texture: " << _set[id][static_cast<int>(ft::mean::texture)] << std::endl;
		outputFile << "Mean perimeter: " << _set[id][static_cast<int>(ft::mean::perimeter)] << std::endl;
		outputFile << "Mean area: " << _set[id][static_cast<int>(ft::mean::area)] << std::endl;
		outputFile << "Mean smoothness: " << _set[id][static_cast<int>(ft::mean::smoothness)] << std::endl;
		outputFile << "Mean compactness: " << _set[id][static_cast<int>(ft::mean::compactness)] << std::endl;
		outputFile << "Mean concavity: " << _set[id][static_cast<int>(ft::mean::concavity)] << std::endl;
		outputFile << "Mean concave points: " << _set[id][static_cast<int>(ft::mean::concave_points)] << std::endl;
		outputFile << "Mean symmetry: " << _set[id][static_cast<int>(ft::mean::symetry)] << std::endl;
		outputFile << "Mean fractal dimension: " << _set[id][static_cast<int>(ft::mean::fractal_dimension)] << std::endl;
		outputFile << "Standard error of radius: " << _set[id][static_cast<int>(ft::error::radius)] << std::endl;
		outputFile << "Standard error of texture: " << _set[id][static_cast<int>(ft::error::texture)] << std::endl;
		outputFile << "Standard error of perimeter: " << _set[id][static_cast<int>(ft::error::perimeter)] << std::endl;
		outputFile << "Standard error of area: " << _set[id][static_cast<int>(ft::error::area)] << std::endl;
		outputFile << "Standard error of smoothness: " << _set[id][static_cast<int>(ft::error::smoothness)] << std::endl;
		outputFile << "Standard error of compactness: " << _set[id][static_cast<int>(ft::error::compactness)] << std::endl;
		outputFile << "Standard error of concavity: " << _set[id][static_cast<int>(ft::error::concavity)] << std::endl;
		outputFile << "Standard error of concave points: " << _set[id][static_cast<int>(ft::error::concave_points)] << std::endl;
		outputFile << "Standard error of symmetry: " << _set[id][static_cast<int>(ft::error::symetry)] << std::endl;
		outputFile << "Standard error of fractal dimension: " << _set[id][static_cast<int>(ft::error::fractal_dimension)] << std::endl;
		outputFile << "Worst radius: " << _set[id][static_cast<int>(ft::worst::radius)] << std::endl;
		outputFile << "Worst texture: " << _set[id][static_cast<int>(ft::worst::texture)] << std::endl;
		outputFile << "Worst perimeter: " << _set[id][static_cast<int>(ft::worst::perimeter)] << std::endl;
		outputFile << "Worst area: " << _set[id][static_cast<int>(ft::worst::area)] << std::endl;
		outputFile << "Worst smoothness: " << _set[id][static_cast<int>(ft::worst::smoothness)] << std::endl;
		outputFile << "Worst compactness: " << _set[id][static_cast<int>(ft::worst::compactness)] << std::endl;
		outputFile << "Worst concavity: " << _set[id][static_cast<int>(ft::worst::concavity)] << std::endl;
		outputFile << "Worst concave points: " << _set[id][static_cast<int>(ft::worst::concave_points)] << std::endl;
		outputFile << "Worst symmetry: " << _set[id][static_cast<int>(ft::worst::symetry)] << std::endl;
		outputFile << "Worst fractal dimension: " << _set[id][static_cast<int>(ft::worst::fractal_dimension)] << std::endl;
		outputFile << "---------------------------------------" << std::endl;
		outputFile.close();
	} else
		std::cout << "Failed to open the output file." << std::endl;

}

void dataset::print_norm(int id) {

	std::ofstream outputFile("output2.txt", std::ios::app);

	if (outputFile.is_open()) {
			
		outputFile << "---------------------------------------         " << "id: " << id << std::endl;
		outputFile << "Mean radius: " << _norm[id][static_cast<int>(ft::mean::radius)] << std::endl;
		outputFile << "Mean texture: " << _norm[id][static_cast<int>(ft::mean::texture)] << std::endl;
		outputFile << "Mean perimeter: " << _norm[id][static_cast<int>(ft::mean::perimeter)] << std::endl;
		outputFile << "Mean area: " << _norm[id][static_cast<int>(ft::mean::area)] << std::endl;
		outputFile << "Mean smoothness: " << _norm[id][static_cast<int>(ft::mean::smoothness)] << std::endl;
		outputFile << "Mean compactness: " << _norm[id][static_cast<int>(ft::mean::compactness)] << std::endl;
		outputFile << "Mean concavity: " << _norm[id][static_cast<int>(ft::mean::concavity)] << std::endl;
		outputFile << "Mean concave points: " << _norm[id][static_cast<int>(ft::mean::concave_points)] << std::endl;
		outputFile << "Mean symmetry: " << _norm[id][static_cast<int>(ft::mean::symetry)] << std::endl;
		outputFile << "Mean fractal dimension: " << _norm[id][static_cast<int>(ft::mean::fractal_dimension)] << std::endl;
		outputFile << "Standard error of radius: " << _norm[id][static_cast<int>(ft::error::radius)] << std::endl;
		outputFile << "Standard error of texture: " << _norm[id][static_cast<int>(ft::error::texture)] << std::endl;
		outputFile << "Standard error of perimeter: " << _norm[id][static_cast<int>(ft::error::perimeter)] << std::endl;
		outputFile << "Standard error of area: " << _norm[id][static_cast<int>(ft::error::area)] << std::endl;
		outputFile << "Standard error of smoothness: " << _norm[id][static_cast<int>(ft::error::smoothness)] << std::endl;
		outputFile << "Standard error of compactness: " << _norm[id][static_cast<int>(ft::error::compactness)] << std::endl;
		outputFile << "Standard error of concavity: " << _norm[id][static_cast<int>(ft::error::concavity)] << std::endl;
		outputFile << "Standard error of concave points: " << _norm[id][static_cast<int>(ft::error::concave_points)] << std::endl;
		outputFile << "Standard error of symmetry: " << _norm[id][static_cast<int>(ft::error::symetry)] << std::endl;
		outputFile << "Standard error of fractal dimension: " << _norm[id][static_cast<int>(ft::error::fractal_dimension)] << std::endl;
		outputFile << "Worst radius: " << _norm[id][static_cast<int>(ft::worst::radius)] << std::endl;
		outputFile << "Worst texture: " << _norm[id][static_cast<int>(ft::worst::texture)] << std::endl;
		outputFile << "Worst perimeter: " << _norm[id][static_cast<int>(ft::worst::perimeter)] << std::endl;
		outputFile << "Worst area: " << _norm[id][static_cast<int>(ft::worst::area)] << std::endl;
		outputFile << "Worst smoothness: " << _norm[id][static_cast<int>(ft::worst::smoothness)] << std::endl;
		outputFile << "Worst compactness: " << _norm[id][static_cast<int>(ft::worst::compactness)] << std::endl;
		outputFile << "Worst concavity: " << _norm[id][static_cast<int>(ft::worst::concavity)] << std::endl;
		outputFile << "Worst concave points: " << _norm[id][static_cast<int>(ft::worst::concave_points)] << std::endl;
		outputFile << "Worst symmetry: " << _norm[id][static_cast<int>(ft::worst::symetry)] << std::endl;
		outputFile << "Worst fractal dimension: " << _norm[id][static_cast<int>(ft::worst::fractal_dimension)] << std::endl;
		outputFile << "---------------------------------------" << std::endl;
		outputFile.close();
	} else
		std::cout << "Failed to open the output file." << std::endl;
}

void dataset::process_line (std::string line, int id) {

	int count = 0;
	std::string token;
	std::stringstream ss(line);

	while (!ss.eof()) {
		std::getline(ss, token, ',');
		if (count == 1)
		{
			_set[id][0] = (token == "M" ? 0 : 1);
		}
		else if (count) {
			try { insert_features(count, stod(token), id); } 
			catch (std::exception) {}
		}
		count++;
	}
}

void dataset::insert_features(int features, double number, int id) {

	int j = features > 11 && features <= 21 ? 11 : 21;

	if (features <= 11) {

		int i = 1;
		while (_set[id][i] != -1 && i <= 11)
			i++;
		_set[id][i] = number;
	}
	else if (features > 10 && features <= 20) {

		while (_set[id][j] != -1 && j <= 21)
			j++;
		_set[id][j] = number;
	}
	else {

		while (_set[id][j] != -1 && j <= 31)
			j++;
		_set[id][j] = number;
	}

}

/*------------------------------------- 42 --------------------------------------*/