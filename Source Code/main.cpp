#include <iostream>
#include "Vector2DMaths.h"
#include "Vector3DMaths.h"
using namespace std;

int main()
{
	
	int choice;
	do
	{
		Vector2D(10.0f/5, 20.0f/5).printVector();
		Vector2DMaths::scalarMultiply(Vector2D(10.0f, 20.0f), 1.0f / 5.0f).printVector();
		cout << "what question do you want to answer" << endl; 
		cout << "[0]testEngine   [1]A   [2]B   [3]C   [10] exit" << endl;
		cin >> choice;

		switch(choice)
		{
			case 0:
			{
				float a, b, c;
				Vector2D vectorA, vectorB, vectorC;
				Vector3D vector3DA,vector3DB, vector3DC;
				vectorA = Vector2D(3.3f, 6.2f);
				vectorB = Vector2D(4.2f, 12.7f);
				vector3DA = Vector3D(1.0f, 4.5f, 8.3f);
				vector3DB = Vector3D(12.6f, -4.5f, 6.7f);

				cout << "add Vector" << endl;
				cout << "2D:" <<endl;
				vectorC = Vector2DMaths::addVector(vectorA, vectorB);
				vectorC.printVector();
				cout << endl << "3D:" << endl;
				vector3DC = Vector3DMaths::addVector(vector3DA, vector3DB);
				vector3DC.printVector();
				cout << endl << endl;

				cout << "subtract Vector" << endl;
				cout << "2D: " << endl;
				vectorC = Vector2DMaths::subtractVector(vectorA, vectorB);
				vectorC.printVector();
				cout << endl << "3D:" << endl;
				vector3DC = Vector3DMaths::subtractVector(vector3DA, vector3DB);
				vector3DC.printVector();
				cout << endl << endl;

				vectorA = Vector2D(7.5f, 7.5f);
				vectorB = Vector2D(12.0f, 0.0f);
				vector3DA = Vector3D(1.0f, 4.5f, 8.3f);
				vector3DB = Vector3D(12.6f, 0.0f, 6.7f);

				cout << "dot product" << endl;
				cout << "2D:"<< endl;
				float dot = Vector2DMaths::dotProduct(vectorA, vectorB);
				cout << dot << endl;
				cout << "3D:" << endl;
				dot = Vector3DMaths::dotProduct(vector3DA, vector3DB);
				cout << dot << endl << endl;
				

				cout << "normalize 2D:" << endl;
				vectorC = Vector2DMaths::normalize(vectorA);
				cout << "Vector A: " << endl;
				vectorC.printVector();
				cout << endl<< "Vector B:" << endl;
				vectorC = Vector2DMaths::normalize(vectorB);
				vectorC.printVector();
				cout << endl << endl<< "Normalize 3D" << endl;
				vector3DC = Vector3DMaths::normalize(vector3DA);
				cout << "Vector A: " << endl;
				vector3DC.printVector();
				cout << endl << "Vector B:" << endl;
				vector3DC = Vector3DMaths::normalize(vector3DB);
				vector3DC.printVector();
				cout << endl << endl;

				cout << "Rotate (3.0,4.0) by 60 degrees" << endl;
				vectorC = Vector2DMaths::rotateVector(Vector2D(3.0f, 4.0f), 60);
				vectorC.printVector();
				cout << endl << endl;

				cout << "Magnitude of Vector A" << endl;
				cout << "2D:" << endl;
				float mag = Vector2DMaths::getMagnitude(vectorA);
				cout << mag << endl;
				cout << "3D:" << endl;
				 mag = Vector3DMaths::getMagnitude(vector3DA);
				 cout << mag << endl << endl;

				cout << "scalar multiply" << endl;
				float scalar;
				cout << "2D:" << endl;
				cout << "Insert Vector x component" << endl;
				cin >> a;
				cout << "Insert vector y component" << endl;
				cin >> b;
				cout << "by what do you want to scale?" << endl;
				cin >> scalar;
				vectorC = Vector2DMaths::scalarMultiply(Vector2D(a, b), scalar);
				vectorC.printVector();
				cout << endl << "3D:" << endl;
				cout << "Insert Vector x component" << endl;
				cin >> a;
				cout << "Insert vector y component" << endl;
				cin >> b;
				cout << "Insert vector z component" << endl;
				cin >> c;
				cout << "by what do you want to scale?" << endl;
				cin >> scalar;
				vector3DC = Vector3DMaths::scalarMultiply(Vector3D(a, b,c), scalar);
				vector3DC.printVector(); \
				cout << endl;

				cout << "Velocity Vector" << endl;
				vectorC = Vector2DMaths::getVelocityVector(20.0f, 45.0f);
				vectorC.printVector();
				cout << endl;
				cout << "End of Test" << endl;

				break;
			}
		
			case 1:
			{
							Vector2D gravity, initialVel, position, velocity;
							bool hasLanded = false;

							//inputs
							float speed, angle;
							cout << "Insert the speed" << endl;
							cin >> speed;
							cout << "Insert the angle" << endl;
							cin >> angle;

							//given information
							float timeStep = 0.02f;
							gravity = Vector2D(0, -9.81f);
							position = Vector2D(0, 0);

							initialVel = Vector2DMaths::getVelocityVector(speed, angle);
							do
							{
								//v=u+at
								velocity = Vector2DMaths::addVector(initialVel, Vector2DMaths::scalarMultiply(gravity, timeStep));
								initialVel = velocity;

								//Pnew= Pold + vt
								position = Vector2DMaths::addVector(position, Vector2DMaths::scalarMultiply(velocity, timeStep));

								// if position is less than 0, means that the projectile has hit the "ground"
								if (position.Y <= 0)
								{
									hasLanded = true;
								}

								position.printVector();
								cout << "          ";
								velocity.printVector();
								cout << endl;
								

							} while (!hasLanded);

				break;
			}
			case 2:
			{
				
				Vector3D gravity, position, initialVel, force, velocity, impulse;
				bool hasLanded = false;
				float timeStep = 0.02f, time, currentTime = 0.0f;
				float x, y, z;
				//inputs
				cout << "For how long was the force applied to the object? " << endl;
				cin >> time;
				cout << "Insert X component of force" << endl;
				cin >> x;
				cout << "Insert y component of force" << endl;
				cin >> y;
				cout << "Insert z component of force" << endl;
				cin >> z;
				

				gravity = Vector3D(0, -9.81f, 0);
				position = Vector3D(0, 0, 0);
				force = Vector3D(x, y, z);
				
				//assuming object is at rest before impulse is applied
				initialVel = Vector3D(0, 0, 0);
				//assuming object weight
				float mass = 0.5f;
				impulse = Vector3DMaths::scalarMultiply(force, time);

				initialVel = Vector3DMaths::addVector(initialVel, Vector3DMaths::scalarMultiply(Vector3DMaths::scalarMultiply(force, time), 1.0f/mass));
				do
				{
						//v = u + at
						velocity = Vector3DMaths::addVector(initialVel, Vector3DMaths::scalarMultiply(gravity,timeStep));
						initialVel = velocity;
						//Pnew = Pold +vt
						position = Vector3DMaths::addVector(position, Vector3DMaths::scalarMultiply(velocity, timeStep));
					
					
					if (position.Y <= 0)
					{
						hasLanded = true;
					}

					
					position.printVector();
					cout << "          ";
					velocity.printVector();
					cout << endl;


				} while (!hasLanded);
				break;
				
			}
			case 3:
			{
				bool ballHasStopped = false;
				Vector2D cueInitVel, cueFinalVel, ballInitVel,ballFinVel, cuePos,cueInitPos, ballPos,ballInitPos, rotDamp;
				float angle, mass, radius, cuePosf, timeStep, contactPoint;

				//given info
				cueInitVel = Vector2D(0.0, 4.00f);
				Vector2D cueInitVelCopy = Vector2D(0.0, 4.00f);
				rotDamp = Vector2D(0.0, -0.1f);
				cueInitPos = Vector2D(0.0, 0.0);
				mass = 0.4f;
				ballInitPos = Vector2D(0, 0.70f);
				//26 mm = 0.026m(si unit)
				radius = 0.026f; 

				//Assumed
				timeStep = 0.02f;

				//input
				cout << "At what angle did the cue ball collided with the ball?" << endl;
				cin >> angle;
				

			 	do
				{
					
					cueFinalVel = Vector2DMaths::addVector(cueInitVel, Vector2DMaths::scalarMultiply(rotDamp, timeStep));
					 
					cueInitVel = cueFinalVel;
					cuePos = Vector2DMaths::addVector(cueInitPos, Vector2DMaths::scalarMultiply(cueFinalVel, timeStep));
				
					//check for contact with the ball
					float collision = Vector2DMaths::getMagnitude(Vector2DMaths::subtractVector(cuePos, ballInitPos));
					if (collision > radius+radius)
					{
						cueInitPos = cuePos;
					}
					else
					{
						ballHasStopped = true;
					}

					cuePos.printVector();
					cout << "          ";
					cueFinalVel.printVector();
					cout << endl;



				} while (!ballHasStopped);
				ballHasStopped = false;
				
				cout << "The cueBall has struck the ball" << endl;
				system("Pause");

				//V of ball = squareroot(Ucue^2 - Vcue^2)
				float ballVelocity = sqrtf((Vector2DMaths::getMagnitude(cueInitVelCopy)*Vector2DMaths::getMagnitude(cueInitVelCopy))- (Vector2DMaths::getMagnitude(cueFinalVel)*Vector2DMaths::getMagnitude(cueFinalVel)));
				ballInitVel = Vector2DMaths::getVelocityVector(ballVelocity, angle);
				
				//rotate the damping
				rotDamp = Vector2DMaths::rotateVector(rotDamp,360-angle);
				
				do
				{
					//v = u + at;
					ballFinVel = Vector2DMaths::addVector(ballInitVel, Vector2DMaths::scalarMultiply(rotDamp, timeStep));
					ballInitVel = ballFinVel;

					//pnew = pold + vt;
					ballPos = Vector2DMaths::addVector(ballInitPos, Vector2DMaths::scalarMultiply(ballFinVel, timeStep));

					//stops the loop if the velocity is insufficient to move the ball's position in a positive direction 
					// i stopped the loop here, i believe its incorrect but it would have kept decreasing in the y axis and eventually decrease in the x axis which is not realistic for the question.
					if (ballInitPos.Y < ballPos.Y)
					{
						ballInitPos = ballPos;
					}
					else
					{
						ballHasStopped = true;
					}
					

					ballPos.printVector();
					cout << "          ";
					ballFinVel.printVector();
					cout << endl;

				} while (!ballHasStopped);
				break;
			}
			case 10:
			{
				cout << "You have exit the program" << endl;
				break;
			}
			default:
			{
				cout << "That is not an available option" << endl;
				break;
			}
		}
		system("PAUSE");
		system("cls");
	} while (choice !=10);
	
		return 0;
}
