Point gravity(Point a, Point b, Point c) { 
	double x=(a.x+b.x+c.x)/3, y=(a.y+b.y+c.y)/3;
	return Point(x,y);
}
Point incenter(Point a, Point b, Point c) {  
     double A=dis(b,c), B=dis(a,c), C=dis(a,b);
     double S=A+B+C; 
     double x=(A*a.x+B*b.x+C*c.x)/S, y=(A*a.y+B*b.y+C*c.y)/S;
	 return Point(x,y);	
}
Point Circum(Point a, Point b, Point c) { 
	double x1=a.x,y1=a.y, x2=b.x,y2=b.y, x3=c.x,y3=c.y;
	double a1=2*(x2-x1), b1=2*(y2-y1), c1=x2*x2+y2*y2-x1*x1-y1*y1;
	double a2=2*(x3-x2), b2=2*(y3-y2), c2=x3*x3+y3*y3-x2*x2-y2*y2;
	double x=(c1*b2-c2*b1)/(a1*b2-a2*b1), y=(a1*c2-a2*c1)/(a1*b2-a2*b1);
	return Point(x,y);
}
Point ortho(Point a, Point b, Point c){  
	double A1=b.x-c.x, B1=b.y-c.y, C1=A1*a.y-B1*a.x;
	double A2=a.x-c.x, B2=a.y-c.y, C2=A2*b.y-B2*b.x;
	double x=(A1*C2-A2*C1)/(A2*B1-A1*B2), y=(B1*C2-B2*C1)/(A2*B1-A1*B2);
	return Point(x,y);
}

