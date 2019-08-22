/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <OpenGl_GlFunctions.hxx>
#include <OpenGl_GlCore11.hxx>

void bind_OpenGl_GlCore11(py::module &mod){

py::class_<OpenGl_GlCore11> cls_OpenGl_GlCore11(mod, "OpenGl_GlCore11", "OpenGL 1.1 core. Notice that all functions within this structure are actually exported by system GL library. The main purpose for these hint - to control visibility of functions per GL version (global functions should not be used directly to achieve this effect!).");

// Constructors

// Fields

// Methods
cls_OpenGl_GlCore11.def("glRotated", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRotated, "None", py::arg("theAngleDegrees"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glScaled", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glScaled, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glTranslated", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTranslated, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glBegin", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glBegin, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glEnd", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glEnd, "None");
cls_OpenGl_GlCore11.def("glVertex2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex2d, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex2f, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glVertex2i, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glVertex2s, "None", py::arg("theX"), py::arg("theY"));
cls_OpenGl_GlCore11.def("glVertex3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex3d, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex3f, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glVertex3i, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glVertex3s, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_OpenGl_GlCore11.def("glVertex4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glVertex4d, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glVertex4f, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glVertex4i, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glVertex4s, "None", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theW"));
cls_OpenGl_GlCore11.def("glVertex2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex2dv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex2fv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex2iv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex2sv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glVertex3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex3dv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex3fv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex3iv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex3sv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glVertex4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glVertex4dv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glVertex4fv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glVertex4iv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glVertex4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glVertex4sv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glNormal3b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glNormal3b, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glNormal3d, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glNormal3f, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glNormal3i, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glNormal3s, "None", py::arg("nx"), py::arg("ny"), py::arg("nz"));
cls_OpenGl_GlCore11.def("glNormal3bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glNormal3bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glNormal3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glNormal3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glNormal3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glNormal3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glNormal3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glIndexd", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glIndexd, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexf", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glIndexf, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexi", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glIndexi, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexs", (void (OpenGl_GlCore11::*)(GLshort)) &OpenGl_GlCore11::glIndexs, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexub", (void (OpenGl_GlCore11::*)(GLubyte)) &OpenGl_GlCore11::glIndexub, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexdv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glIndexdv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexfv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glIndexfv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexiv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glIndexiv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexsv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glIndexsv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glIndexubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glIndexubv, "None", py::arg("c"));
cls_OpenGl_GlCore11.def("glColor3b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glColor3b, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glColor3d, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glColor3f, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glColor3i, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glColor3s, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3ub", (void (OpenGl_GlCore11::*)(GLubyte, GLubyte, GLubyte)) &OpenGl_GlCore11::glColor3ub, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3ui", (void (OpenGl_GlCore11::*)(GLuint, GLuint, GLuint)) &OpenGl_GlCore11::glColor3ui, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor3us", (void (OpenGl_GlCore11::*)(GLushort, GLushort, GLushort)) &OpenGl_GlCore11::glColor3us, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"));
cls_OpenGl_GlCore11.def("glColor4b", (void (OpenGl_GlCore11::*)(GLbyte, GLbyte, GLbyte, GLbyte)) &OpenGl_GlCore11::glColor4b, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glColor4d, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glColor4f, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glColor4i, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glColor4s, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4ub", (void (OpenGl_GlCore11::*)(GLubyte, GLubyte, GLubyte, GLubyte)) &OpenGl_GlCore11::glColor4ub, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4ui", (void (OpenGl_GlCore11::*)(GLuint, GLuint, GLuint, GLuint)) &OpenGl_GlCore11::glColor4ui, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor4us", (void (OpenGl_GlCore11::*)(GLushort, GLushort, GLushort, GLushort)) &OpenGl_GlCore11::glColor4us, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glColor3bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glColor3bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glColor3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glColor3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glColor3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glColor3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3ubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glColor3ubv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3uiv", (void (OpenGl_GlCore11::*)(const GLuint *)) &OpenGl_GlCore11::glColor3uiv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor3usv", (void (OpenGl_GlCore11::*)(const GLushort *)) &OpenGl_GlCore11::glColor3usv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4bv", (void (OpenGl_GlCore11::*)(const GLbyte *)) &OpenGl_GlCore11::glColor4bv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glColor4dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glColor4fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glColor4iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glColor4sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4ubv", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glColor4ubv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4uiv", (void (OpenGl_GlCore11::*)(const GLuint *)) &OpenGl_GlCore11::glColor4uiv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glColor4usv", (void (OpenGl_GlCore11::*)(const GLushort *)) &OpenGl_GlCore11::glColor4usv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glTexCoord1d", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glTexCoord1d, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1f", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glTexCoord1f, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1i", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glTexCoord1i, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord1s", (void (OpenGl_GlCore11::*)(GLshort)) &OpenGl_GlCore11::glTexCoord1s, "None", py::arg("s"));
cls_OpenGl_GlCore11.def("glTexCoord2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord2d, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord2f, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glTexCoord2i, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord2s, "None", py::arg("s"), py::arg("t"));
cls_OpenGl_GlCore11.def("glTexCoord3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord3d, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord3f, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glTexCoord3i, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord3s, "None", py::arg("s"), py::arg("t"), py::arg("r"));
cls_OpenGl_GlCore11.def("glTexCoord4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glTexCoord4d, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glTexCoord4f, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glTexCoord4i, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glTexCoord4s, "None", py::arg("s"), py::arg("t"), py::arg("r"), py::arg("q"));
cls_OpenGl_GlCore11.def("glTexCoord1dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord1dv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord1fv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord1iv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord1sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord1sv, "None", py::arg("theVec1"));
cls_OpenGl_GlCore11.def("glTexCoord2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord2dv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord2fv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord2iv, "None", py::arg("theVec2"));
cls_OpenGl_GlCore11.def("glTexCoord2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord2sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glTexCoord3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord3dv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord3fv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord3iv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord3sv, "None", py::arg("theVec3"));
cls_OpenGl_GlCore11.def("glTexCoord4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glTexCoord4dv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glTexCoord4fv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glTexCoord4iv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glTexCoord4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glTexCoord4sv, "None", py::arg("theVec4"));
cls_OpenGl_GlCore11.def("glMatrixMode", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glMatrixMode, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glOrtho", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glOrtho, "None", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNearVal"), py::arg("theFarVal"));
cls_OpenGl_GlCore11.def("glFrustum", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glFrustum, "None", py::arg("theLeft"), py::arg("theRight"), py::arg("theBottom"), py::arg("theTop"), py::arg("theNearVal"), py::arg("theFarVal"));
cls_OpenGl_GlCore11.def("glPushMatrix", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPushMatrix, "None");
cls_OpenGl_GlCore11.def("glPopMatrix", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopMatrix, "None");
cls_OpenGl_GlCore11.def("glLoadIdentity", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glLoadIdentity, "None");
cls_OpenGl_GlCore11.def("glLoadMatrixd", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glLoadMatrixd, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glLoadMatrixf", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glLoadMatrixf, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glMultMatrixd", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glMultMatrixd, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glMultMatrixf", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glMultMatrixf, "None", py::arg("theMatrix"));
cls_OpenGl_GlCore11.def("glLineStipple", (void (OpenGl_GlCore11::*)(GLint, GLushort)) &OpenGl_GlCore11::glLineStipple, "None", py::arg("theFactor"), py::arg("thePattern"));
cls_OpenGl_GlCore11.def("glPolygonStipple", (void (OpenGl_GlCore11::*)(const GLubyte *)) &OpenGl_GlCore11::glPolygonStipple, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glGetPolygonStipple", (void (OpenGl_GlCore11::*)(GLubyte *)) &OpenGl_GlCore11::glGetPolygonStipple, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPushAttrib", (void (OpenGl_GlCore11::*)(GLbitfield)) &OpenGl_GlCore11::glPushAttrib, "", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPopAttrib", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopAttrib, "None");
cls_OpenGl_GlCore11.def("glPushClientAttrib", (void (OpenGl_GlCore11::*)(GLbitfield)) &OpenGl_GlCore11::glPushClientAttrib, "None", py::arg("theMask"));
cls_OpenGl_GlCore11.def("glPopClientAttrib", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopClientAttrib, "None");
cls_OpenGl_GlCore11.def("glShadeModel", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glShadeModel, "", py::arg("theMode"));
cls_OpenGl_GlCore11.def("glLightf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glLightf, "None", py::arg("theLight"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLighti", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glLighti, "None", py::arg("theLight"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glLightfv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glLightiv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetLightfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetLightfv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetLightiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetLightiv, "None", py::arg("theLight"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightModelf", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glLightModelf, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightModeli", (void (OpenGl_GlCore11::*)(GLenum, GLint)) &OpenGl_GlCore11::glLightModeli, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glLightModelfv", (void (OpenGl_GlCore11::*)(GLenum, const GLfloat *)) &OpenGl_GlCore11::glLightModelfv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glLightModeliv", (void (OpenGl_GlCore11::*)(GLenum, const GLint *)) &OpenGl_GlCore11::glLightModeliv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMaterialf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glMaterialf, "None", py::arg("face"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glMateriali", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glMateriali, "None", py::arg("face"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glMaterialfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glMaterialfv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMaterialiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glMaterialiv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetMaterialfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetMaterialfv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetMaterialiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetMaterialiv, "None", py::arg("face"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glColorMaterial", (void (OpenGl_GlCore11::*)(GLenum, GLenum)) &OpenGl_GlCore11::glColorMaterial, "None", py::arg("face"), py::arg("mode"));
cls_OpenGl_GlCore11.def("glClipPlane", (void (OpenGl_GlCore11::*)(GLenum, const GLdouble *)) &OpenGl_GlCore11::glClipPlane, "", py::arg("thePlane"), py::arg("theEquation"));
cls_OpenGl_GlCore11.def("glGetClipPlane", (void (OpenGl_GlCore11::*)(GLenum, GLdouble *)) &OpenGl_GlCore11::glGetClipPlane, "None", py::arg("thePlane"), py::arg("theEquation"));
cls_OpenGl_GlCore11.def("glIsList", (GLboolean (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glIsList, "", py::arg("theList"));
cls_OpenGl_GlCore11.def("glDeleteLists", (void (OpenGl_GlCore11::*)(GLuint, GLsizei)) &OpenGl_GlCore11::glDeleteLists, "None", py::arg("theList"), py::arg("theRange"));
cls_OpenGl_GlCore11.def("glGenLists", (GLuint (OpenGl_GlCore11::*)(GLsizei)) &OpenGl_GlCore11::glGenLists, "None", py::arg("theRange"));
cls_OpenGl_GlCore11.def("glNewList", (void (OpenGl_GlCore11::*)(GLuint, GLenum)) &OpenGl_GlCore11::glNewList, "None", py::arg("theList"), py::arg("theMode"));
cls_OpenGl_GlCore11.def("glEndList", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glEndList, "None");
cls_OpenGl_GlCore11.def("glCallList", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glCallList, "None", py::arg("theList"));
cls_OpenGl_GlCore11.def("glCallLists", (void (OpenGl_GlCore11::*)(GLsizei, GLenum, const GLvoid *)) &OpenGl_GlCore11::glCallLists, "None", py::arg("theNb"), py::arg("theType"), py::arg("theLists"));
cls_OpenGl_GlCore11.def("glListBase", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glListBase, "None", py::arg("theBase"));
cls_OpenGl_GlCore11.def("glRasterPos2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos2d, "", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos2f, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2i", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glRasterPos2i, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos2s", (void (OpenGl_GlCore11::*)(GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos2s, "None", py::arg("x"), py::arg("y"));
cls_OpenGl_GlCore11.def("glRasterPos3d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos3d, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos3f, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint)) &OpenGl_GlCore11::glRasterPos3i, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos3s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos3s, "None", py::arg("x"), py::arg("y"), py::arg("z"));
cls_OpenGl_GlCore11.def("glRasterPos4d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRasterPos4d, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRasterPos4f, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4i", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glRasterPos4i, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos4s", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRasterPos4s, "None", py::arg("x"), py::arg("y"), py::arg("z"), py::arg("w"));
cls_OpenGl_GlCore11.def("glRasterPos2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos2dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos2fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos2iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos2sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos2sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos3dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos3fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos3iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos3sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos3sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glRasterPos4dv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glRasterPos4fv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4iv", (void (OpenGl_GlCore11::*)(const GLint *)) &OpenGl_GlCore11::glRasterPos4iv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRasterPos4sv", (void (OpenGl_GlCore11::*)(const GLshort *)) &OpenGl_GlCore11::glRasterPos4sv, "None", py::arg("theVec"));
cls_OpenGl_GlCore11.def("glRectd", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble, GLdouble, GLdouble)) &OpenGl_GlCore11::glRectd, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRectf", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glRectf, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRecti", (void (OpenGl_GlCore11::*)(GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glRecti, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRects", (void (OpenGl_GlCore11::*)(GLshort, GLshort, GLshort, GLshort)) &OpenGl_GlCore11::glRects, "None", py::arg("x1"), py::arg("y1"), py::arg("x2"), py::arg("y2"));
cls_OpenGl_GlCore11.def("glRectdv", (void (OpenGl_GlCore11::*)(const GLdouble *, const GLdouble *)) &OpenGl_GlCore11::glRectdv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectfv", (void (OpenGl_GlCore11::*)(const GLfloat *, const GLfloat *)) &OpenGl_GlCore11::glRectfv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectiv", (void (OpenGl_GlCore11::*)(const GLint *, const GLint *)) &OpenGl_GlCore11::glRectiv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glRectsv", (void (OpenGl_GlCore11::*)(const GLshort *, const GLshort *)) &OpenGl_GlCore11::glRectsv, "None", py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glTexGend", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble)) &OpenGl_GlCore11::glTexGend, "", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGenf", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11::glTexGenf, "None", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGeni", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11::glTexGeni, "None", py::arg("coord"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glTexGendv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLdouble *)) &OpenGl_GlCore11::glTexGendv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glTexGenfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11::glTexGenfv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glTexGeniv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11::glTexGeniv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGendv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble *)) &OpenGl_GlCore11::glGetTexGendv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGenfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetTexGenfv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glGetTexGeniv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetTexGeniv, "None", py::arg("coord"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glPrioritizeTextures", (void (OpenGl_GlCore11::*)(GLsizei, const GLuint *, const GLclampf *)) &OpenGl_GlCore11::glPrioritizeTextures, "", py::arg("n"), py::arg("textures"), py::arg("priorities"));
cls_OpenGl_GlCore11.def("glAreTexturesResident", (GLboolean (OpenGl_GlCore11::*)(GLsizei, const GLuint *, GLboolean *)) &OpenGl_GlCore11::glAreTexturesResident, "None", py::arg("n"), py::arg("textures"), py::arg("residences"));
cls_OpenGl_GlCore11.def("glDrawPixels", (void (OpenGl_GlCore11::*)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11::glDrawPixels, "", py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11.def("glCopyPixels", (void (OpenGl_GlCore11::*)(GLint, GLint, GLsizei, GLsizei, GLenum)) &OpenGl_GlCore11::glCopyPixels, "None", py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("type"));
cls_OpenGl_GlCore11.def("glBitmap", (void (OpenGl_GlCore11::*)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *)) &OpenGl_GlCore11::glBitmap, "None", py::arg("width"), py::arg("height"), py::arg("xorig"), py::arg("yorig"), py::arg("xmove"), py::arg("ymove"), py::arg("bitmap"));
cls_OpenGl_GlCore11.def("glPixelZoom", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glPixelZoom, "None", py::arg("xfactor"), py::arg("yfactor"));
cls_OpenGl_GlCore11.def("glFogf", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glFogf, "", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glFogi", (void (OpenGl_GlCore11::*)(GLenum, GLint)) &OpenGl_GlCore11::glFogi, "None", py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11.def("glFogfv", (void (OpenGl_GlCore11::*)(GLenum, const GLfloat *)) &OpenGl_GlCore11::glFogfv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glFogiv", (void (OpenGl_GlCore11::*)(GLenum, const GLint *)) &OpenGl_GlCore11::glFogiv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glMap1d", (void (OpenGl_GlCore11::*)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) &OpenGl_GlCore11::glMap1d, "", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("stride"), py::arg("order"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap1f", (void (OpenGl_GlCore11::*)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) &OpenGl_GlCore11::glMap1f, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("stride"), py::arg("order"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap2d", (void (OpenGl_GlCore11::*)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *)) &OpenGl_GlCore11::glMap2d, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("ustride"), py::arg("uorder"), py::arg("v1"), py::arg("v2"), py::arg("vstride"), py::arg("vorder"), py::arg("points"));
cls_OpenGl_GlCore11.def("glMap2f", (void (OpenGl_GlCore11::*)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *)) &OpenGl_GlCore11::glMap2f, "None", py::arg("target"), py::arg("u1"), py::arg("u2"), py::arg("ustride"), py::arg("uorder"), py::arg("v1"), py::arg("v2"), py::arg("vstride"), py::arg("vorder"), py::arg("points"));
cls_OpenGl_GlCore11.def("glGetMapdv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLdouble *)) &OpenGl_GlCore11::glGetMapdv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glGetMapfv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11::glGetMapfv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glGetMapiv", (void (OpenGl_GlCore11::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11::glGetMapiv, "None", py::arg("target"), py::arg("query"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord1d", (void (OpenGl_GlCore11::*)(GLdouble)) &OpenGl_GlCore11::glEvalCoord1d, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1f", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glEvalCoord1f, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glEvalCoord1dv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord1fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glEvalCoord1fv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord2d", (void (OpenGl_GlCore11::*)(GLdouble, GLdouble)) &OpenGl_GlCore11::glEvalCoord2d, "None", py::arg("u"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord2f", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat)) &OpenGl_GlCore11::glEvalCoord2f, "None", py::arg("u"), py::arg("v"));
cls_OpenGl_GlCore11.def("glEvalCoord2dv", (void (OpenGl_GlCore11::*)(const GLdouble *)) &OpenGl_GlCore11::glEvalCoord2dv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glEvalCoord2fv", (void (OpenGl_GlCore11::*)(const GLfloat *)) &OpenGl_GlCore11::glEvalCoord2fv, "None", py::arg("u"));
cls_OpenGl_GlCore11.def("glMapGrid1d", (void (OpenGl_GlCore11::*)(GLint, GLdouble, GLdouble)) &OpenGl_GlCore11::glMapGrid1d, "None", py::arg("un"), py::arg("u1"), py::arg("u2"));
cls_OpenGl_GlCore11.def("glMapGrid1f", (void (OpenGl_GlCore11::*)(GLint, GLfloat, GLfloat)) &OpenGl_GlCore11::glMapGrid1f, "None", py::arg("un"), py::arg("u1"), py::arg("u2"));
cls_OpenGl_GlCore11.def("glMapGrid2d", (void (OpenGl_GlCore11::*)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble)) &OpenGl_GlCore11::glMapGrid2d, "None", py::arg("un"), py::arg("u1"), py::arg("u2"), py::arg("vn"), py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glMapGrid2f", (void (OpenGl_GlCore11::*)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat)) &OpenGl_GlCore11::glMapGrid2f, "None", py::arg("un"), py::arg("u1"), py::arg("u2"), py::arg("vn"), py::arg("v1"), py::arg("v2"));
cls_OpenGl_GlCore11.def("glEvalPoint1", (void (OpenGl_GlCore11::*)(GLint)) &OpenGl_GlCore11::glEvalPoint1, "None", py::arg("i"));
cls_OpenGl_GlCore11.def("glEvalPoint2", (void (OpenGl_GlCore11::*)(GLint, GLint)) &OpenGl_GlCore11::glEvalPoint2, "None", py::arg("i"), py::arg("j"));
cls_OpenGl_GlCore11.def("glEvalMesh1", (void (OpenGl_GlCore11::*)(GLenum, GLint, GLint)) &OpenGl_GlCore11::glEvalMesh1, "None", py::arg("mode"), py::arg("i1"), py::arg("i2"));
cls_OpenGl_GlCore11.def("glEvalMesh2", (void (OpenGl_GlCore11::*)(GLenum, GLint, GLint, GLint, GLint)) &OpenGl_GlCore11::glEvalMesh2, "None", py::arg("mode"), py::arg("i1"), py::arg("i2"), py::arg("j1"), py::arg("j2"));
cls_OpenGl_GlCore11.def("glFeedbackBuffer", (void (OpenGl_GlCore11::*)(GLsizei, GLenum, GLfloat *)) &OpenGl_GlCore11::glFeedbackBuffer, "", py::arg("theSize"), py::arg("theType"), py::arg("theBuffer"));
cls_OpenGl_GlCore11.def("glPassThrough", (void (OpenGl_GlCore11::*)(GLfloat)) &OpenGl_GlCore11::glPassThrough, "None", py::arg("token"));
cls_OpenGl_GlCore11.def("glSelectBuffer", (void (OpenGl_GlCore11::*)(GLsizei, GLuint *)) &OpenGl_GlCore11::glSelectBuffer, "None", py::arg("theSize"), py::arg("theBuffer"));
cls_OpenGl_GlCore11.def("glInitNames", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glInitNames, "None");
cls_OpenGl_GlCore11.def("glLoadName", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glLoadName, "None", py::arg("theName"));
cls_OpenGl_GlCore11.def("glPushName", (void (OpenGl_GlCore11::*)(GLuint)) &OpenGl_GlCore11::glPushName, "None", py::arg("theName"));
cls_OpenGl_GlCore11.def("glPopName", (void (OpenGl_GlCore11::*)()) &OpenGl_GlCore11::glPopName, "None");
cls_OpenGl_GlCore11.def("glClearAccum", (void (OpenGl_GlCore11::*)(GLfloat, GLfloat, GLfloat, GLfloat)) &OpenGl_GlCore11::glClearAccum, "", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11.def("glAccum", (void (OpenGl_GlCore11::*)(GLenum, GLfloat)) &OpenGl_GlCore11::glAccum, "None", py::arg("theOp"), py::arg("theValue"));
cls_OpenGl_GlCore11.def("glEdgeFlag", (void (OpenGl_GlCore11::*)(GLboolean)) &OpenGl_GlCore11::glEdgeFlag, "", py::arg("theFlag"));
cls_OpenGl_GlCore11.def("glEdgeFlagv", (void (OpenGl_GlCore11::*)(const GLboolean *)) &OpenGl_GlCore11::glEdgeFlagv, "None", py::arg("theFlag"));
cls_OpenGl_GlCore11.def("glIndexPointer", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glIndexPointer, "None", py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glEdgeFlagPointer", (void (OpenGl_GlCore11::*)(GLsizei, const GLvoid *)) &OpenGl_GlCore11::glEdgeFlagPointer, "None", py::arg("theStride"), py::arg("thePtr"));
// cls_OpenGl_GlCore11.def("glGetPointerv", (void (OpenGl_GlCore11::*)(GLenum, GLvoid **)) &OpenGl_GlCore11::glGetPointerv, "None", py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11.def("glInterleavedArrays", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glInterleavedArrays, "None", py::arg("theFormat"), py::arg("theStride"), py::arg("thePointer"));
cls_OpenGl_GlCore11.def("glVertexPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glVertexPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glNormalPointer", (void (OpenGl_GlCore11::*)(GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glNormalPointer, "None", py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glColorPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glColorPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glTexCoordPointer", (void (OpenGl_GlCore11::*)(GLint, GLenum, GLsizei, const GLvoid *)) &OpenGl_GlCore11::glTexCoordPointer, "None", py::arg("theSize"), py::arg("theType"), py::arg("theStride"), py::arg("thePtr"));
cls_OpenGl_GlCore11.def("glEnableClientState", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glEnableClientState, "None", py::arg("theCap"));
cls_OpenGl_GlCore11.def("glDisableClientState", (void (OpenGl_GlCore11::*)(GLenum)) &OpenGl_GlCore11::glDisableClientState, "None", py::arg("theCap"));

// Enums

}