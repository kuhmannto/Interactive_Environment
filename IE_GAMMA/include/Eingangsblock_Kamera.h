#ifndef EINGANGSBLOCK_KAMERA_H
#define EINGANGSBLOCK_KAMERA_H

#include "Block.h"
#include "AusgangImpl.h"


class Eingangsblock_Kamera : public Block
{
    public:
        Eingangsblock_Kamera();

        enum Typ {IMAGE};

        Eingangsblock_Kamera(const string& name) : Block(name)
        {
            a1 = new AusgangImpl<ofImage>("a1");
            this->ausgangHinzufuegen(a1);


            int IMAGE_HEIGHT = 480;
            int IMAGE_WIDTH = 640;
            vidGrabber.setVerbose(false);
            vidGrabber.initGrabber(IMAGE_WIDTH,IMAGE_HEIGHT);

            image.allocate(IMAGE_WIDTH,IMAGE_HEIGHT,OF_IMAGE_COLOR);
        }

        void update()
        {
            vidGrabber.update();
            if (vidGrabber.isFrameNew()){
                unsigned char *pixels = vidGrabber.getPixels();
                image.setFromPixels(pixels,image.getWidth(),image.getHeight(),OF_IMAGE_COLOR);
                a1->setzeDaten(&image);
            }
        }

        void draw(){
            // nothing to do here
        }

        void trigger(int key = 0){
            vidGrabber.videoSettings();
        }

    protected:
    private:
        AusgangImpl<ofImage>* a1;
        ofVideoGrabber vidGrabber;
        ofImage image;

};

#endif // EINGANGSBLOCK_KAMERA_H
