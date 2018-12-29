//
//  graph.cpp
//  final project
//
//  Created by shan on 4/14/17.
//  Copyright © 2017 shan. All rights reserved.
//

#include "graphs.hpp"
#include "shapes.hpp"
#include <cmath>

enum page {menu,infoConfirm, gameplay, gameResume, gameOver};

page currentPage;
GLdouble width, height;
int wd;
int staus = 0;
int t;
int pause = 0;
int update;
int maxium;
string name;

Car A;

Lane Llane, Rlane;

Coord buttonnew, resume, confirm;
Button New, Resume, Confirm;

vector<Barrier> BA;

vector<Lane> Mlane;

vector<string> Location = {};

vector<string> Name = {};

vector<int> Score = {};

vector<string> BarrierLoc = {};

random_device rd;
//int size = rd() % 1001-100;
int size = 500;



int mouseX, mouseY;

// check if mouse and rectangle r are overlapping and changes color of
// r accordingly
void updateButtonNewColor(Coord &r, int x, int y) {
    // if the mouse overlaps with A.a, set r to be indigo
    if (buttonnew.isOverlapping(x, y)) {
        New.setFill(76, 0, 153);
//        cout<<x<<endl;
//        cout<<y<<endl;
    } else {
        // not overlapping, so return to original color
        New.setFill((127/255.0), 1, 0);
    }
    if (resume.isOverlapping(x, y)) {
        Resume.setFill(76, 0, 153);
        //        cout<<x<<endl;
        //        cout<<y<<endl;
    } else {
        // not overlapping, so return to original color
        Resume.setFill((127/255.0), 1, 0);
    }
    if (confirm.isOverlapping(x, y)) {
        Confirm.setFill(76, 0, 153);
        //        cout<<x<<endl;
        //        cout<<y<<endl;
    } else {
        // not overlapping, so return to original color
        Confirm.setFill((127/255.0), 1, 0);
    }
}

void setup() {
    // initialize rectangle fields
    A.a.setWidth(30);
    A.a.setHeight(60);
    A.a.setTopLeft(335, 440);
    A.a.setTopRight(365,440);
    A.a.setBottomLeft(335,500);
    A.a.setBottomRight(365,500);
    
    A.setFill(0,0,255);
    
    
    Llane.a.setWidth(20);
    Llane.a.setHeight(500);
    Llane.a.setTopLeft(20, 0);
    Llane.a.setTopRight(40,0);
    Llane.a.setBottomLeft(20,500);
    Llane.a.setBottomRight(40,500);
//    Llane.setCoord(leftlane);
    
    Llane.setFill(255, 255, 255);
    
    Rlane.a.setWidth(20);
    Rlane.a.setHeight(500);
    Rlane.a.setTopLeft(660, 0);
    Rlane.a.setTopRight(680,0);
    Rlane.a.setBottomLeft(660,500);
    Rlane.a.setBottomRight(680,500);
  //  Rlane.setCoord(rightlane);
    
    
    Rlane.setFill(255, 255, 255);
    BA.resize(size);
    for (int i = 0; i < size; ++i) {
        BA[i].a.setWidth(30);
        BA[i].a.setHeight(20);
        BA[i].a.setTopLeft(rd() % 590+40, rd() % 9900+(-10000));
        BA[i].a.setTopRight(BA[i].a.getTopLeftX()+30, BA[i].a.getTopLeftY());
        BA[i].a.setBottomLeft(BA[i].a.getTopLeftX(), BA[i].a.getTopLeftY()+20);
        BA[i].a.setBottomRight(BA[i].a.getTopLeftX()+30, BA[i].a.getTopLeftY()+20);
        
        
        BA[i].setFill((127/255.0), 1, 0);
    }
    for (int i = 0; i < size + 1; ++i){
        if (BA[i+1].a.getTopLeftY()<= BA[i].a.getTopLeftY()){
            maxium = i;
        }
        else if (BA[i+1].a.getTopLeftY()> BA[i].a.getTopLeftY()){
            maxium = i-1;
        }
      //  cout << BA[i].a.getTopLeftY()<<endl;
       // cout << maxium << endl;
    }
   // cout << size << endl;
     Mlane.resize(size);
  //  Mlane.resize(size);
    
    for(int i = 0; i < size; ++i) {
        Mlane[i].a.setWidth(20);
        Mlane[i].a.setHeight(100);
        Mlane[i].a.setTopLeft(340, 400-180*i);
        Mlane[i].a.setTopRight(360,400-180*i);
        Mlane[i].a.setBottomLeft(340,500-180*i);
       Mlane[i].a.setBottomRight(360,500-180*i);
        
      //  Mlane[i].setCoord(middlelane[i]);
        
        Mlane[i].setFill(255, 255, 255);
    }
    

}

void init() {
//    size = abs(size);
//    cout << size <<endl;
    width = 700;
    height = 500;
    
    // default page
    currentPage = menu;
    
    // initialize mouse coordinates
    mouseX = mouseY = -1;
    setup();
    int t = 0;
    }

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glColor3f(0, 0, 1);
}

/* DISPLAY HELPER FUNCTIONS */

void displayMenu() {
    string message = "Car race";
    // set color to lime green
    glColor3f(50/255.0, 205/255.0, 50/255.0);
    glRasterPos2i(300, 100);
    
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
    
    buttonnew.setWidth(280);
    buttonnew.setHeight(70);
    buttonnew.setTopLeft(200, 200);
    buttonnew.setTopRight(480, 200);
    buttonnew.setBottomLeft(200, 270);
    buttonnew.setBottomRight(480, 270);
    New.setCoord(buttonnew);
    
    
 //   New.setFill((127/255.0), 1, 0);
    //New.setOutsideColor(0.5, 0.5, 0.5);
    
    New.draw();
    string choice1 = "Start new";
    // set color to lime green
    glColor3f(255,255,255);
    glRasterPos2i(300, 245);
    
    for (int i = 0; i < choice1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, choice1[i]);
    }
    updateButtonNewColor(buttonnew, mouseX, mouseY);
    
    resume.setWidth(280);
    resume.setHeight(70);
    resume.setTopLeft(200, 300);
    resume.setTopRight(480, 300);
    resume.setBottomLeft(200, 370);
    resume.setBottomRight(480, 370);
    Resume.setCoord(resume);
    
 //   Resume.setFill((127/255.0), 1, 0);
    
    Resume.draw();
    
    string choice2 = "Resume";
    // set color to lime green
    glColor3f(255,255,255);
    glRasterPos2i(300, 345);
    
    for (int i = 0; i < choice2.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, choice2[i]);
    }
    
    updateButtonNewColor(resume, mouseX, mouseY);
}

void displayInfo() {
    string info = "Your name is: "+A.getName();
    // set color to lime green
    glColor3f(255,255,255);
    glRasterPos2i(215, 200);
    
    for (int i = 0; i < info.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, info[i]);
        
    }
    string confo = "Space key to pause, s key to save the process, left right key to move.";
    // set color to lime green
    glColor3f(255,255,255);
    glRasterPos2i(50, 240);
    
    for (int i = 0; i < confo.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, confo[i]);
        
    }

    
    
    confirm.setWidth(280);
    confirm.setHeight(70);
    confirm.setTopLeft(200, 300);
    confirm.setTopRight(480, 300);
    confirm.setBottomLeft(200, 370);
    confirm.setBottomRight(480, 370);
    Confirm.setCoord(confirm);

    Confirm.draw();
    
    string conf = "Confirm";
    // set color to lime green
    glColor3f(255,255,255);
    glRasterPos2i(300, 345);
    
    for (int i = 0; i < conf.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, conf[i]);
    }

    updateButtonNewColor(confirm, mouseX, mouseY);
    
}

void displayGamePlay() {
    // Draw shapes
    //glColor3f(1.0, 0, 0);
   
    Llane.draw();
    Rlane.draw();
    for (int i = 0; i < size; ++i) {
        Mlane[i].draw();
//        cout <<"topleftx "<<middlelane[i].getTopLeftY()<<endl;
    }

    for (int i = 0; i < size; ++i) {
        BA[i].draw();
        if (A.a.isOverlapping(BA[i].a)) {
            currentPage = gameOver;
            staus = 1;
//            cout<<staus<<endl;
        }
    }
    A.draw();
    
    if (BA[maxium].a.getTopLeftY() > 500){
        currentPage = gameOver;
    }

    for (int i = 0; i < size;++i){
        stringstream ss;
        ss << t;
        string tnow = ss.str();
        string display1 = "Time: "+tnow;
        glColor3f(255,255,255);
        glRasterPos2i(50, 30);
        for (int i = 0; i < display1.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, display1[i]);
        }


//    cout <<"topleftx "<<A.a.getTopLeftX()<<endl;
//    cout<<"width "<<A.a.getWidth()<<endl;
//    cout<<"toplefty "<<A.a.getTopLeftY()<<endl;
    
    }
}
void displayGameResume() {
//    string message = "Top 5 list";
//    // set color to lime green
//    glColor3f(255, 0, 0);
//    glRasterPos2i(210, 200);
//    for (int i = 0; i < message.length(); ++i) {
//        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
//    
//    }
    ifstream in_file("/Users/apple/Desktop/score.txt");
            if (in_file) {
                string str;
                while (in_file && getline(in_file, str)) {
                    istringstream iss(str);
                    string g_name;
                    string g_score;
                    string tlx_coord;
                    string tly_coord;
                    string trx_coord;
                    string try_coord;
                    string blx_coord;
                    string bly_coord;
                    string brx_coord;
                    string bry_coord;
                    string s_height;
                    string s_width;
                    string g_size;
                    iss>> g_name;
                    iss>> g_score;
                    iss>> tlx_coord;
                    iss>> tly_coord;
                    iss>> trx_coord;
                    iss>> try_coord;
                    iss>> blx_coord;
                    iss>> bly_coord;
                    iss>> brx_coord;
                    iss>> bry_coord;
                    iss>> s_height;
                    iss>> s_width;
                    iss>> g_size;
//                    cout << g_score<< endl;
//                    cout<< g_name<<endl;
//                    cout<< g_score;
//                    cout<< tlx_coord <<endl;
//                    cout<< tly_coord <<endl;
//                    cout<< trx_coord <<endl;
//                    cout<< try_coord <<endl;
//                    cout<< blx_coord <<endl;
//                    cout<< bly_coord <<endl;
//                    cout<< brx_coord <<endl;
//                    cout<< bry_coord <<endl;
//                    cout<< s_height <<endl;
//                    cout<< s_width <<endl;
                  //cout<< g_size <<endl;
                    
                    if (name == g_name){
                        int a = stoi(g_score);
//                        cout << a << endl;
                        t = a;
//                        cout << t << endl;
                        A.setName(g_name);
                        A.a.setTopLeft(stoi(tlx_coord),stoi(tly_coord));
                        A.a.setTopRight(stoi(trx_coord),stoi(try_coord));
                        A.a.setBottomLeft(stoi(blx_coord),stoi(bly_coord));
                        A.a.setBottomRight(stoi(brx_coord),stoi(bry_coord));
                        A.a.setHeight(stoi(s_height));
                        A.a.setWidth(stoi(s_width));
                        for (int i = 0; i < stoi(g_size); ++i){
                            iss >> tlx_coord;
                            iss >> tly_coord;
                            iss >> trx_coord;
                            iss >> try_coord;
                            iss >> blx_coord;
                            iss >> bly_coord;
                            iss >> brx_coord;
                            iss >> bry_coord;
                            BA[i].a.setTopLeft(stoi(tlx_coord),stoi(tly_coord));
                            BA[i].a.setTopRight(stoi(trx_coord),stoi(try_coord));
                            BA[i].a.setBottomLeft(stoi(blx_coord),stoi(bly_coord));
                            BA[i].a.setBottomRight(stoi(brx_coord),stoi(bry_coord));
                        }
                    
                        currentPage = gameplay;
                    }else {
                        string error = "The user does not exsit!";
                        // set color to lime green
                        glColor3f(255, 0, 0);
                        glRasterPos2i(210, 200);
                        for (int i = 0; i < error.length(); ++i) {
                            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, error[i]);
                        }

                    }
                    
                }
            }

}
void displayGameOver() {
    // Draw strings
    if (A.a.getTopLeftX() < 60 ||A.a.getTopRightX() > 650){
        string message = "You drive out of the Lane!";
        // set color to lime green
        glColor3f(255, 0, 0);
        glRasterPos2i(210, 200);
        for (int i = 0; i < message.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
        }
    }
    if (staus == 1){
            string message = "You crashed into the barrier!";
            // set color to lime green
            glColor3f(255, 0, 0);
            glRasterPos2i(210, 200);
            for (int i = 0; i < message.length(); ++i) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
            }
        
            stringstream ss;
            ss << t;
            string tfinal = ss.str();
            string tupdate = "Time you used: "+ tfinal +"ms.";
            glColor3f(255, 0, 0);
            glRasterPos2i(210, 230);
            for (int i = 0; i < tupdate.length(); ++i) {
                glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, tupdate[i]);
            }

    }
    if (BA[maxium].a.getTopLeftY()>500){
        string win = "You win!";
        // set color to lime green
        glColor3f(255, 0, 0);
        glRasterPos2i(210, 200);
        for (int i = 0; i < win.length(); ++i) {
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, win[i]);
        }

    }


    string message = "GAME OVER.";
//    cout<<staus<<endl;
    // set color to lime green
    glColor3f(255, 0, 0);
    glRasterPos2i(210, 260);
    for (int i = 0; i < message.length(); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
    // DRAW THINGS
    
    switch(currentPage) {
        case menu:
            displayMenu();
            break;
        case infoConfirm:
            displayInfo();
            break;
        case gameplay:
            displayGamePlay();
            break;
        case gameOver:
            displayGameOver();
            break;
        case  gameResume:
            displayGameResume();
            break;
    }
    
    glFlush();  // Render now
}
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    if (key == 32 && currentPage == gameplay){
        pause++;
        update = pause % 2;
       // cout<<pause<<endl;
       // cout<<"update"<<update<<endl;
    }
    
    if (key == 115 && currentPage == gameplay){
        pause++;
        string pram;
        string barrierco;
        update = pause % 2;
        //  cout<<pause<<endl;
        // cout<<"update"<<update<<endl;
        string point = to_string(A.a.getTopLeftX())+" "+ to_string(A.a.getTopLeftY())+" "+ to_string(A.a.getTopRightX())+" "+ to_string(A.a.getTopRightY())+" "+ to_string(A.a.getBottomLeftX())+" "+ to_string(A.a.getBottomLeftY())+" "+ to_string(A.a.getBottomRightX())+" "+ to_string(A.a.getBottomRightY())+" "+to_string(A.a.getHeight())+" "+to_string(A.a.getWidth())+" "+to_string(size);
        for (int i = 0; i < size; ++i) {
            pram = to_string(BA[i].a.getTopLeftX())+" "+ to_string(BA[i].a.getTopLeftY())+" "+ to_string(BA[i].a.getTopRightX())+" "+ to_string(BA[i].a.getTopRightY())+" "+ to_string(BA[i].a.getBottomLeftX())+" "+ to_string(BA[i].a.getBottomLeftY())+" "+ to_string(BA[i].a.getBottomRightX())+" "+ to_string(BA[i].a.getBottomRightY());
            barrierco = barrierco +" "+ pram;
        }
        //  cout<<barrierco<<endl;
        Name.push_back(A.getName());
        Score.push_back(t);
        Location.push_back(point);
        BarrierLoc.push_back(barrierco);
        ofstream out_file("/Users/apple/Desktop/score.txt",std::ios_base::app);
        if (out_file) {
            for(int i = 0; i < Name.size(); i++){
                out_file << Name[i]<<" " <<Score[i]<<" "<<Location[i]<<BarrierLoc[i]<< endl;
            }
        }
        out_file.close();
    }

    glutPostRedisplay();
    
    return;
}

void kbdS(int key, int x, int y) {
    if (currentPage == gameplay) {
        switch(key) {
                case GLUT_KEY_LEFT:
                if (update == 0){
                    if (A.a.getTopLeftX() >= 60) {
                        A.move(-10, 0);
//                        A.a.setTopLeft(A.a.getTopLeftX()-10,A.a.getTopLeftY());
//                        A.a.setTopRight(A.a.getTopRightX()-10,A.a.getTopRightY());
//                        A.a.setBottomLeft(A.a.getBottomLeftX()-10,A.a.getBottomLeftY());
//                        A.a.setBottomRight(A.a.getBottomRightX()-10,A.a.getBottomRightY());
                    }else{
                        currentPage=gameOver;
                    }
                }// moves the A.a left
                break;
            case GLUT_KEY_RIGHT:
                if (update == 0){
                    if (A.a.getTopRightX() <= 650) {
                        A.move(10, 0);
//                        A.a.setTopLeft(A.a.getTopLeftX()+10,A.a.getTopLeftY());
//                        A.a.setTopRight(A.a.getTopRightX()+10,A.a.getTopRightY());
//                        A.a.setBottomLeft(A.a.getBottomLeftX()+10,A.a.getBottomLeftY());
//                        A.a.setBottomRight(A.a.getBottomRightX()+10,A.a.getBottomRightY());
                    }else{
                        currentPage=gameOver;
                    }
                }// moves the A.a right
                break;
        }
    }
    glutPostRedisplay();
    
    return;
}

void cursor(int x, int y) {
    //A.a.setTopLeft(x, y);
    
    mouseX = x;
    mouseY = y;
    
    //updateColor(r, x, y);
    
    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&buttonnew.isOverlapping(mouseX,mouseY)&& currentPage == menu) {
        currentPage = infoConfirm;
        updateButtonNewColor(buttonnew,x,y);
    }
    
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&resume.isOverlapping(mouseX,mouseY)&& currentPage == menu) {
        currentPage = gameResume;
        updateButtonNewColor(resume,x,y);
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&confirm.isOverlapping(mouseX,mouseY)&& currentPage == infoConfirm) {
        currentPage = gameplay;
        updateButtonNewColor(confirm,x,y);
    }

    glutPostRedisplay();
}

void timer(int extra) {
    if (update == 0){
    if (currentPage == gameplay) {
        if (A.a.getBottomLeftY()>300){
            A.move(0, -1);
//            A.a.setTopLeft(A.a.getTopLeftX(),A.a.getTopLeftY()-1);
//            A.a.setTopRight(A.a.getTopRightX(),A.a.getTopRightY()-1);
//            A.a.setBottomLeft(A.a.getBottomLeftX(),A.a.getBottomLeftY()-1);
//            A.a.setBottomRight(A.a.getBottomRightX(),A.a.getBottomRightY()-1);
        }
        for (int i = 0; i < size; ++i) {
            BA[i].move(0,1);
//            BA[i].a.setTopLeft(BA[i].a.getTopLeftX(),BA[i].a.getTopLeftY()+1);
//            BA[i].a.setTopRight(BA[i].a.getTopRightX(),BA[i].a.getTopRightY()+1);
//            BA[i].a.setBottomLeft(BA[i].a.getBottomLeftX(),BA[i].a.getBottomLeftY()+1);
//            BA[i].a.setBottomRight(BA[i].a.getBottomRightX(),BA[i].a.getBottomRightY()+1);
        }
            for (int i = 0; i < size; ++i) {
            Mlane[i].move(0,1);
//            middlelane[i].setTopLeft(middlelane[i].getTopLeftX(),middlelane[i].getTopLeftY()+1);
//            middlelane[i].setTopRight(middlelane[i].getTopRightX(),middlelane[i].getTopRightY()+1);
//            middlelane[i].setBottomLeft(middlelane[i].getBottomLeftX(),middlelane[i].getBottomLeftY()+1);
//            middlelane[i].setBottomRight(middlelane[i].getBottomRightX(),middlelane[i].getBottomRightY()+1);
        }
        for (int i = 0; i < size; ++i) {
        if (BA[i].a.isOverlapping(A.a)) {
            currentPage = gameOver;
            staus = 1;
        }else{
            t++;
        }
    }
    }
    }
    glutPostRedisplay();
    glutTimerFunc(2, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    
    cout<< "Please type your name here"<<endl;
    cin >> name;
    A.setName(name);
    
    init();
    
    glutInit(&argc, argv);          // Initialize GLUT
    
    glutInitDisplayMode(GLUT_RGBA);
    
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(350, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Car race" /* title */ );
    
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    
    // Our own OpenGL initialization
    initGL();
    
    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    
    glutKeyboardFunc(kbd);
    
    
    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);
    
    // handles mouse movement
    glutPassiveMotionFunc(cursor);
    
    // handles mouse click
    glutMouseFunc(mouse);
    
    // handles timer
 //   if (update == 1) {
        glutTimerFunc(0, timer, 0);
 //   }
    
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}

