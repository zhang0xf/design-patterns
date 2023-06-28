#ifndef COMPONENT_H
#define COMPONENT_H

// 我们假定已经存在一个(Component)类(VisualComponent)
class VisualComponent {
public:
    VisualComponent();

    virtual void Draw();
    virtual void Resize();

    // ...
};

// 定义(VisualComponent)的一个子类(Decorator),我们将生成的(Decorator)的子类获取不同的装饰.
// (Decorator)装饰由(_componet)实例变量引用的(VisualComponent),这个实例变量在构造器中被初始化.
// 对于(VisualComponent)接口中定义的每一个操作,(Decorator)类都定义了一个缺省的实现, 这一实现将请求转发给(_componet).
class Decorator : public VisualComponent {
public:
    Decorator(VisualComponent *);

    virtual void Draw();
    virtual void Resize();

    // ...
private:
    VisualComponent *_componet;
};

// (Decorator)子类定义了特殊的装饰功能, 如: (BorderDecorator)类为它所包含的组件添加了一个边框
class BorderDecorator : public Decorator {
public:
    BorderDecorator(VisualComponent *, int boderWidth);

    virtual void Draw();

private:
    void DrawBorder(int); // 辅助操作,由它绘制边框

private:
    int _width;
};

// (ScrollDecorator)给可视组件添加滚动条
class ScrollDecorator : public Decorator {
public:
    ScrollDecorator(VisualComponent *);
};

// (DropShadowDecorator)给可视组件添加阴影
class DropShadowDecorator : public Decorator {
public:
    DropShadowDecorator(VisualComponent *);
};

// 现在我们组合这些类的实例以提供不同的装饰效果.
// 创建一个具有边界的可滚动的(TextView), 另见(component_main.cpp)

#endif