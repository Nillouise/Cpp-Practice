Point global;
Point foo_bar(Point arg)
{
    Point local = arg,//拷贝构造函数
    *heap = new Point(global);//拷贝构造函数;
    *heap = local;//赋值构造函数;
    Point pa[4] = {local,*heap};//这里应该有两个拷贝构造函数，两个是默认初始化
    return *heap;
}
