#include <iostream>
#include <math.h>
#include <time.h>

class Point {
public:
	int x;
	int y;

	void print() {
		std::cout << "x:" << x << " y:" << y << std::endl;
	}
};

class Circle {
public:
	Point p;
	int r;

	void print() {
		std::cout << "x:" << p.x << " y:" << p.y << " r:" << r << std::endl;
	}
};

class Box {
public:
	Point p;
	int w;
	int h;
	void print() {
		std::cout << "x:" << p.x << " y:" << p.y << " w:" << w << " h:" << h << std::endl;
	}
};

int calculate_hypotenuse(Point a, Point b) {
	int result = 0;

	// Find the distance (Length) of X and Y  

	int x_Distance = b.x - a.x;
	int y_Distance = b.y - a.y;

	// Now that we have the distance (Length)
	// of x and y, use Pythagoras theorem 
	// to get the distance (length of hypotenuse) 
	// between Point a and Point b 
	result = sqrt(pow(x_Distance, 2) + pow(y_Distance, 2));

	return result;
}


int main() {

	srand(time(NULL));

	// Point Collision
	Point player_point;
	player_point.x = rand() % 10 + 1;
	player_point.y = rand() % 10 + 1;

	Point npc_point;
	npc_point.x = rand() % 10 + 1;
	npc_point.y = rand() % 10 + 1;

	// Circle Collision
	Circle player_circle;
	player_circle.p.x = rand() % 10 + 1;
	player_circle.p.y = rand() % 10 + 1;
	player_circle.r = rand() % 2 + 1;
	
	Circle npc_circle;
	npc_circle.p.x = rand() % 10 + 1;
	npc_circle.p.y = rand() % 10 + 1;
	npc_circle.r = rand() % 2 + 1;

	// Box Collision
	Box player_box;
	player_box.p.x = rand() % 10 + 1;
	player_box.p.y = rand() % 10 + 1;
	player_box.w = rand() % 3 + 1;
	player_box.h = rand() % 3 + 1;

	Box npc_box;
	npc_box.p.x = rand() % 10 + 1;
	npc_box.p.y = rand() % 10 + 1;
	npc_box.w = rand() % 3 + 1;
	npc_box.h = rand() % 3 + 1;
	

	while (true) {

		// Point Collision check
		if (calculate_hypotenuse(player_point, npc_point) == 0)
		{
			std::cout << "Point Collision" << std::endl;
			player_point.print();
			npc_point.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No Collision between points" << std::endl;
			player_point.print();
			npc_point.print();
		}

		player_point.x = rand() % 10 + 1;
		player_point.y = rand() % 10 + 1;

		// Circle Collision check
		if (calculate_hypotenuse(player_circle.p, npc_circle.p) < (player_circle.r + npc_circle.r))
		{
			std::cout << "Circle Collision between circles" << std::endl;
			player_circle.print();
			npc_circle.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No Collision" << std::endl;
			player_circle.print();
			npc_circle.print();
		}
		if (calculate_hypotenuse(player_point, player_circle.p) <= (player_circle.r))
		{
			std::cout << "Point has collided with circle so collision has occured" << std::endl;
			player_point.print();
			player_circle.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No collision between a point and circle" << std::endl;
			player_circle.print();
			player_point.print();
		}

		if (calculate_hypotenuse(player_box.p, npc_box.p) < (player_box.w + npc_box.w) || (calculate_hypotenuse(player_box.p, npc_box.p)) < (player_box.h + npc_box.h) || (calculate_hypotenuse();
		{
			std::cout << "Box collision" << std::endl;
			player_box.print();
			npc_box.print();
			std::cin.get();
		}
		else
		{
			std::cout << "No collison between boxes" << std::endl;
			player_box.print();
			npc_box.print();
		}

		player_circle.p.x = rand() % 10 + 1;
		player_circle.p.y = rand() % 10 + 1;

		player_box.p.x = rand() % 10 + 1;
		player_box.p.y = rand() % 10 + 1;

	}

	return 0;
}