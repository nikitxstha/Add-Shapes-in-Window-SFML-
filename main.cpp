#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

int main()
{
	//Create Window
	RenderWindow window(VideoMode({ 1200,800 }), "My Window");

	//To Add Rectangle
	RectangleShape rectangle({ 120.f , 80.f });  //( 120.f is width and 80.f is height)
	rectangle.setFillColor(Color::Blue);
	rectangle.setOrigin({ 60.f , 40.f });
	rectangle.setPosition({ 600.f , 400.f });

	//To Add Circle
	CircleShape circle({ 100.f });
	circle.setFillColor(Color::Cyan);
	circle.setOrigin({ 50.f , 50.f });
	circle.setPosition({ 300.f , 200.f });

	//Transformations
	rectangle.setRotation(degrees(45.f));
	rectangle.setScale({ 1.5f , 2.0f});     //Width of rectangle increases 1.5x and height by 2.0x

	circle.setRotation(degrees(45.f));   //No Change 
	circle.setScale({ 1.5f , 2.0f });    //Makes Circle Oval (Elliptic) and rotated cause the local co-ordinate system is rotated too


	//Outline
	rectangle.setOutlineThickness({ 3.0f });  //Creates a boundary(outline) around Rectangle
	rectangle.setOutlineColor(Color::Green);

	circle.setOutlineThickness({ 2.0f });  //Creates a boundary(outline) around circle
	circle.setOutlineColor(Color::Red);


	//Infinity Loop to display window unless closed
	while (window.isOpen()) {

		//Loop to handle events like Closing Window/Resizing Window/Taking Keyboard/Mouse Input
		while (optional event = window.pollEvent()) {

			//To close window
			if (event->is<Event::Closed>()) {
				window.close();
			}
		}
		//Set Background Color
		window.clear(Color::Black);

		//Display Rectangle
		window.draw(rectangle);
		
		//Display Circle
		window.draw(circle);
		
		//Display Window
		window.display();
	}
}