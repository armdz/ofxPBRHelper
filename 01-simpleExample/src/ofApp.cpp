#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    
    pbr.setup(1024);
    
    cam.setupPerspective(false, 60, 1, 12000);
    
    scene = bind(&ofApp::renderScene, this);
    
    gui.setup();
    
    ofxPBRFiles::getInstance()->setup("ofxPBRAssets");
    pbrHelper.setup(&pbr, ofxPBRFiles::getInstance()->getPath() + "/settings", true);
    pbrHelper.addLight(&pbrLight1, "light1");
    pbrHelper.addMaterial(&floorMaterial, "floor");
    pbrHelper.addMaterial(&cubeMaterial, "cube");
    pbrHelper.addMaterial(&sphereMaterial, "sphere");
    pbrHelper.addMaterial(&coneMaterial, "cone");
    pbrHelper.addMaterial(&cylinderMaterial, "cylinder");
    pbrHelper.addMaterial(&planeMaterial, "plane");
    pbrHelper.addCubeMap(&cubeMap1, "cubeMap1");
    
    ofSetSphereResolution(32);
    ofSetConeResolution(32, 1);
    ofSetBoxResolution(1);
    ofSetCylinderResolution(32, 2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    pbr.makeDepthMap(scene);
    
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    
    cam.begin();
    pbr.drawEnvironment(&cam);
    scene();
    cam.end();
    
    ofDisableDepthTest();
    ofEnableAlphaBlending();
    
    gui.begin();
    {
        ImGui::Begin("control panel");
        {
            ImGui::Checkbox("show gui", &showGui);
            if(ImGui::Checkbox("enable camera control", &mouseInput)){
                if (mouseInput){
                    cam.enableMouseInput();
                } else {
                    cam.disableMouseInput();
                }
            }
        }
        ImGui::End();
        if(showGui){
            ImGui::Begin("ofxPBR");
            pbrHelper.drawGui();
            ImGui::End();
        }
    }
    gui.end();
}

//--------------------------------------------------------------
void ofApp::renderScene(){
    ofEnableDepthTest();
    pbr.begin(&cam);
    
    planeMaterial.begin(&pbr);
    ofDrawPlane(-350 * 2, 150, 0, 300, 300);
    planeMaterial.end();
    
    sphereMaterial.begin(&pbr);
    ofDrawSphere(-350, 150, 0, 150);
    sphereMaterial.end();
    
    coneMaterial.begin(&pbr);
    ofPushMatrix();
    ofTranslate(0, 150, 0);
    ofRotateX(180);
    ofDrawCone(0, 0, 0, 150, 300);
    ofPopMatrix();
    coneMaterial.end();
    
    cubeMaterial.begin(&pbr);
    ofDrawBox(350, 150, 0, 300, 300, 300);
    cubeMaterial.end();
    
    cylinderMaterial.begin(&pbr);
    ofDrawCylinder(350 * 2, 150, 0, 150, 300);
    cylinderMaterial.end();
    
    floorMaterial.begin(&pbr);
    ofDrawBox(0, -5, 0, 5000, 10, 5000);
    floorMaterial.end();
    
    pbr.end();
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
