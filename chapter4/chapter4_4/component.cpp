#include "component.h"

VisualComponent::VisualComponent() {
}

void VisualComponent::Draw() {
}

void VisualComponent::Resize() {
}

Decorator::Decorator(VisualComponent *comnent) :
    _componet(comnent) {
}

void Decorator::Draw() {
    _componet->Draw();
}

void Decorator::Resize() {
    _componet->Resize();
}

BorderDecorator::BorderDecorator(VisualComponent *component, int boderWidth) :
    Decorator(component), _width(boderWidth) {
}

void BorderDecorator::Draw() {
    Decorator::Draw();
    DrawBorder(_width);
}

void BorderDecorator::DrawBorder(int) {
    // ...
}

ScrollDecorator::ScrollDecorator(VisualComponent *component) :
    Decorator(component) {
}

DropShadowDecorator::DropShadowDecorator(VisualComponent *component) :
    Decorator(component) {
}