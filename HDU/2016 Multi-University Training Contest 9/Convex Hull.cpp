#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int MAXN=1010;
const double eps=1e-8;

struct Point {
    double x,y,z;
    Point() {}

    Point(double xx,double yy,double zz):x(xx),y(yy),z(zz) {}

    bool operator <(const Point &t)const {
        if(abs(x - t.x) < eps && abs(y - t.y) < eps) return z < t.z;
        if(abs(x - t.x) < eps) return y < t.y;
        return x < t.x;
    }
    bool operator == (const Point &t)const {
        return abs(x - t.x) < eps && abs(y - t.y) < eps && abs(z - t.z) < eps;
    }
    //两向量之差
    Point operator -(const Point p1) {
        return Point(x-p1.x,y-p1.y,z-p1.z);
    }

    //两向量之和
    Point operator +(const Point p1) {
        return Point(x+p1.x,y+p1.y,z+p1.z);
    }

    //叉乘
    Point operator *(const Point p) {
        return Point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }

    Point operator *(double d) {
        return Point(x*d,y*d,z*d);
    }

    Point operator / (double d) {
        return Point(x/d,y/d,z/d);
    }

    //点乘
    double  operator ^(Point p) {
        return (x*p.x+y*p.y+z*p.z);
    }

    double len2() {
        return x * x + y * y + z * z;
    }

    double len() {
        return sqrt(x * x + y * y + z * z);
    }

    void read() {
        scanf("%lf%lf%lf", &x, &y, &z);
    }

    void show() {
        printf("(%.3f %.3f %.3f)\n", x, y, z);
    }
};

struct Line {

    int a, b;

    Line() {};
    Line(int _a, int _b):a(_a), b(_b) {
        if(a > b) swap(a, b);
    };

    bool operator<(Line &t)const {
        if(a == t.a) return b < t.b;
        return a < t.a;
    }

    bool operator==(Line &t)const {
        return a == t.a && b == t.b;
    }
} line[MAXN*MAXN];
int e;

struct CH3D {
    struct face {
        //表示凸包一个面上的三个点的编号
        int a,b,c;
        //表示该面是否属于最终凸包上的面
        bool ok;
    };
    //初始顶点数
    int n;
    //初始顶点
    Point P[MAXN];
    //凸包表面的三角形数
    int num;
    //凸包表面的三角形
    face F[8*MAXN];
    //凸包表面的三角形
    int g[MAXN][MAXN];

    void read() {
        for(int i = 0; i < n; i ++) P[i].read();
    }
    //向量长度
    double vlen(Point a) {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }
    //叉乘
    Point cross(const Point &a,const Point &b,const Point &c) {
        return Point((b.y-a.y)*(c.z-a.z)-(b.z-a.z)*(c.y-a.y),
                     (b.z-a.z)*(c.x-a.x)-(b.x-a.x)*(c.z-a.z),
                     (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x)
                    );
    }
    //三角形面积*2
    double area(Point a,Point b,Point c) {
        return vlen((b-a)*(c-a));
    }
    //四面体有向体积*6
    double volume(Point a,Point b,Point c,Point d) {
        return (b-a)*(c-a)^(d-a);
    }
    //正：点在面同向
    double dblcmp(Point &p,face &f) {
        Point m=P[f.b]-P[f.a];
        Point n=P[f.c]-P[f.a];
        Point t=p-P[f.a];
        return (m*n)^t;
    }
    void deal(int p,int a,int b) {
        int f=g[a][b];//搜索与该边相邻的另一个平面
        face add;
        if(F[f].ok) {
            if(dblcmp(P[p],F[f])>eps)
                dfs(p,f);
            else {
                add.a=b;
                add.b=a;
                add.c=p;//这里注意顺序，要成右手系
                add.ok=true;
                g[p][b]=g[a][p]=g[b][a]=num;
                F[num++]=add;
            }
        }
    }
    void dfs(int p,int now) { //递归搜索所有应该从凸包内删除的面
        F[now].ok=0;
        deal(p,F[now].b,F[now].a);
        deal(p,F[now].c,F[now].b);
        deal(p,F[now].a,F[now].c);
    }
    bool same(int s,int t) {
        Point &a=P[F[s].a];
        Point &b=P[F[s].b];
        Point &c=P[F[s].c];
        return fabs(volume(a,b,c,P[F[t].a]))<eps &&
               fabs(volume(a,b,c,P[F[t].b]))<eps &&
               fabs(volume(a,b,c,P[F[t].c]))<eps;
    }
    //构建三维凸包
    void create() {
        int i,j,tmp;
        face add;

        num=0;
        if(n<4)return;
        //**********************************************
        //此段是为了保证前四个点不共面
        bool flag=true;
        for(i=1; i<n; i++) {
            if(vlen(P[0]-P[i])>eps) {
                swap(P[1],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
        flag=true;
        //使前三个点不共线
        for(i=2; i<n; i++) {
            if(vlen((P[0]-P[1])*(P[1]-P[i]))>eps) {
                swap(P[2],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
        flag=true;
        //使前四个点不共面
        for(int i=3; i<n; i++) {
            if(fabs((P[0]-P[1])*(P[1]-P[2])^(P[0]-P[i]))>eps) {
                swap(P[3],P[i]);
                flag=false;
                break;
            }
        }
        if(flag)return;
        //*****************************************
        for(i=0; i<4; i++) {
            add.a=(i+1)%4;
            add.b=(i+2)%4;
            add.c=(i+3)%4;
            add.ok=true;
            if(dblcmp(P[i],add)>0)swap(add.b,add.c);
            g[add.a][add.b]=g[add.b][add.c]=g[add.c][add.a]=num;
            F[num++]=add;
        }
        for(i=4; i<n; i++) {
            for(j=0; j<num; j++) {
                if(F[j].ok&&dblcmp(P[i],F[j])>eps) {
                    dfs(i,j);
                    break;
                }
            }
        }
        tmp=num;
        for(i=num=0; i<tmp; i++)
            if(F[i].ok)
                F[num++]=F[i];

    }
    //表面积
    double area() {
        double res=0;
        if(n==3) {
            Point p=cross(P[0],P[1],P[2]);
            res=vlen(p)/2.0;
            return res;
        }
        for(int i=0; i<num; i++)
            res+=area(P[F[i].a],P[F[i].b],P[F[i].c]);
        return res/2.0;
    }
    double volume() {
        double res=0;
        Point tmp(0,0,0);
        for(int i=0; i<num; i++)
            res+=volume(tmp,P[F[i].a],P[F[i].b],P[F[i].c]);
        return fabs(res/6.0);
    }
    //表面三角形个数
    int triangle() {
        return num;
    }
    //表面多边形个数
    int polygon() {
        int i,j,res,flag;
        for(i=res=0; i<num; i++) {
            flag=1;
            for(j=0; j<i; j++)
                if(same(i,j)) {
                    flag=0;
                    break;
                }
            res+=flag;
        }
        return res;
    }
    //点到面的距离
    double ptoface(Point p,int i) {
        return fabs(volume(P[F[i].a],P[F[i].b],P[F[i].c],p)/vlen((P[F[i].b]-P[F[i].a])*(P[F[i].c]-P[F[i].a])));
    }
};

int sgn(double x) {
    if(abs(x) < eps) return 0;
    if(x < eps) return -1;
    return 1;
}

Point po[64*MAXN], poo[64*MAXN], normal;
int pn, pnn;
double a, b, c, d;


double dis_1(Point &p) {
    return abs(a * p.x + b * p.y + c * p.z + d);
}

double mul(Point p1, Point p2, Point p3) {
    return sgn((p1 * p2) ^ p3);
}

void gao(Point &p1, Point &p2) {

    int sgn1 = sgn(a * p1.x + b * p1.y + c * p1.z + d);
    int sgn2 = sgn(a * p2.x + b * p2.y + c * p2.z + d);
    if(sgn1 * sgn2 > 0) return ;
    if(sgn1 == 0 && sgn2 == 0) {
        po[pn ++] = p1;
        po[pn ++] = p2;
        return ;
    }
    double d1 = dis_1(p1);
    double d2 = dis_1(p2);
    if(abs(d1 + d2) < eps) while(1) {};
    po[pn ++] = p1 + (p2 - p1) * (d1 / (d1 + d2));

    return ;
}

bool _cmp(Point &p1, Point &p2) {
    int tmp = mul(normal, p1 - po[0], p2 - po[0]);
    if(tmp > 0)return true;
    else if(tmp == 0 && sgn((p1 - po[0]).len2() - (p2 - po[0]).len2()) < 0) // < 0, not <= 0
        return true;
    else return false;
}

CH3D hull;
int main() {

    int T, q;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++) {
        scanf("%d%d", &hull.n, &q);
        hull.read();
        hull.create();

        e = 0;
        int num = hull.num;
        for(int i = 0; i < num;  i++)if(hull.F[i].ok) {
                line[e ++] = Line(hull.F[i].a, hull.F[i].b);
                line[e ++] = Line(hull.F[i].b, hull.F[i].c);
                line[e ++] = Line(hull.F[i].a, hull.F[i].c);
            }

        sort(line, line + e);
        e = unique(line, line + e) - line;

        printf("Case #%d:\n", cas);
        while(q --) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            pn = 0;

            for(int i = 0; i < e; i ++) gao(hull.P[line[i].a], hull.P[line[i].b]);

            if(pn <= 2) printf("0.000\n");
            else {
                normal = Point(a, b, c);

                sort(po + 1, po + pn, _cmp);

                pnn = 0;
                poo[pnn ++] = po[0];
                for(int i = 1; i < pn; i ++) {
                    if(mul(normal, po[i] - po[0], po[(i + 1) % pn] - po[0])) {
                        poo[pnn ++] = po[i];
                    }
                }

                poo[pnn ++] = po[pn - 1];

                double area = 0;
                for(int i = 0; i < pnn; i ++) {
                    Point t = (poo[i] - poo[0]) * (poo[(i + 1) % pnn] - poo[0]);

                    int sg = sgn(normal ^ t);
                    if(sg > 0) area += t.len();
                    else if(sg > 0) area -= t.len();
                }

                area /= 2;
                printf("%.3f\n", abs(area));

            }
        }
    }
    return 0;
}
