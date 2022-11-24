#pragma once

namespace UI
{
    class UIElement;
    
    class Scene
    {
        public:
        // Some other related code.
        
        //A UIElement added by Scene::Add() stays on the UI
        // until it is removed via Scene::Remove()
        void Add(const UIElement& elem);
        void Remove(const UIElement& elem);
        
        // Some other related code.
    };
}