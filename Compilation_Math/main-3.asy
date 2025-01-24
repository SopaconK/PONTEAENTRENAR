if(!settings.multipleView) settings.batchView=false;
settings.tex="pdflatex";
defaultfilename="main-3";
if(settings.render < 0) settings.render=4;
settings.outformat="";
settings.inlineimage=true;
settings.embed=true;
settings.toolbar=false;
viewportmargin=(2,2);

defaultpen(fontsize(10pt));
size(8cm); // set a reasonable default
usepackage("amsmath");
usepackage("amssymb");
settings.tex="pdflatex";
settings.outformat="pdf";
// Replacement for olympiad+cse5 which is not standard
import geometry;
// recalibrate fill and filldraw for conics
void filldraw(picture pic = currentpicture, conic g, pen fillpen=defaultpen, pen drawpen=defaultpen)
{ filldraw(pic, (path) g, fillpen, drawpen); }
void fill(picture pic = currentpicture, conic g, pen p=defaultpen)
{ filldraw(pic, (path) g, p); }
// some geometry
pair foot(pair P, pair A, pair B) { return foot(triangle(A,B,P).VC); }
pair centroid(pair A, pair B, pair C) { return (A+B+C)/3; }
// cse5 abbreviations
path CP(pair P, pair A) { return circle(P, abs(A-P)); }
path CR(pair P, real r) { return circle(P, r); }
pair IP(path p, path q) { return intersectionpoints(p,q)[0]; }
pair OP(path p, path q) { return intersectionpoints(p,q)[1]; }
path Line(pair A, pair B, real a=0.6, real b=a) { return (a*(A-B)+A)--(b*(B-A)+B); }
// cse5 more useful functions
picture CC() {
picture p=rotate(0)*currentpicture;
currentpicture.erase();
return p;
}
pair MP(Label s, pair A, pair B = plain.S, pen p = defaultpen) {
Label L = s;
L.s = "$"+s.s+"$";
label(L, A, B, p);
return A;
}
pair Drawing(Label s = "", pair A, pair B = plain.S, pen p = defaultpen) {
dot(MP(s, A, B, p), p);
return A;
}
path Drawing(path g, pen p = defaultpen, arrowbar ar = None) {
draw(g, p, ar);
return g;
}

import graph;
size(11.543033701901319cm); real lsf=0.5; pen dps=linewidth(0.7)+fontsize(10); defaultpen(dps); pen ds=black; real xmin=-2.01734812695763,xmax=9.525685574943688,ymin=-1.9539353617289232,ymax=4.57168653701735;
pair A=(0.,0.), B=(1.,0.), C=(2.,0.), D=(3.,0.), F=(4.,1.), G=(3.,1.), H=(5.,0.), I=(6.,0.), J=(6.,1.), K=(5.,1.), L=(6.5,0.5), M=(6.5,1.5), O=(5.5,0.5);
draw(B--C,linewidth(2.)); draw(D--(4.,0.),linewidth(2.)); draw(F--(4.,0.),linewidth(2.)); draw(G--F,linewidth(2.)); draw(G--D,linewidth(2.)); draw(H--I,linewidth(2.)); draw(I--J,linewidth(2.)); draw(K--J,linewidth(2.)); draw(K--H,linewidth(2.)); draw(I--L,linewidth(2.)); draw(L--M,linewidth(2.)); draw(J--M,linewidth(2.)); draw(M--(5.5,1.5),linewidth(2.)); draw((5.5,1.5)--K,linewidth(2.)); draw(H--O,linewidth(2.)); draw(O--L,linewidth(2.)); draw((5.5,1.5)--O,linewidth(2.)); label("$G(0)$",(-0.2552808865638971,0.674232725637997),SE*lsf); label("$G(1)$",(1.252929209027349,0.674232725637997),SE*lsf); label("$G(2)$",(3.253920820999893,1.674728531624268),SE*lsf); label("$G(3)$",(5.747693949353735,2.182442821229241),SE*lsf);
dot(A,ds); dot(B,ds); dot(C,ds); dot(D,ds); dot((4.,0.),ds); dot(F,ds); dot(G,ds); dot(H,ds); dot(I,ds); dot(J,ds); dot(K,ds); dot(L,ds); dot(M,ds); dot((5.5,1.5),ds); dot(O,ds);
clip((xmin,ymin)--(xmin,ymax)--(xmax,ymax)--(xmax,ymin)--cycle);
