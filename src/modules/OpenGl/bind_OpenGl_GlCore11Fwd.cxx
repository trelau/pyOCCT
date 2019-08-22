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
#include <OpenGl_GlCore11Fwd.hxx>

void bind_OpenGl_GlCore11Fwd(py::module &mod){

py::class_<OpenGl_GlCore11Fwd> cls_OpenGl_GlCore11Fwd(mod, "OpenGl_GlCore11Fwd", "OpenGL 1.1 core without deprecated Fixed Pipeline entry points. Notice that all functions within this structure are actually exported by system GL library. The main purpose for these hint - to control visibility of functions per GL version (global functions should not be used directly to achieve this effect!).");

// Constructors

// Fields

// Methods
cls_OpenGl_GlCore11Fwd.def("glClearColor", (void (OpenGl_GlCore11Fwd::*)(GLclampf, GLclampf, GLclampf, GLclampf)) &OpenGl_GlCore11Fwd::glClearColor, "", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11Fwd.def("glClear", (void (OpenGl_GlCore11Fwd::*)(GLbitfield)) &OpenGl_GlCore11Fwd::glClear, "None", py::arg("theMask"));
cls_OpenGl_GlCore11Fwd.def("glColorMask", (void (OpenGl_GlCore11Fwd::*)(GLboolean, GLboolean, GLboolean, GLboolean)) &OpenGl_GlCore11Fwd::glColorMask, "None", py::arg("theRed"), py::arg("theGreen"), py::arg("theBlue"), py::arg("theAlpha"));
cls_OpenGl_GlCore11Fwd.def("glBlendFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum)) &OpenGl_GlCore11Fwd::glBlendFunc, "None", py::arg("sfactor"), py::arg("dfactor"));
cls_OpenGl_GlCore11Fwd.def("glCullFace", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glCullFace, "None", py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glFrontFace", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glFrontFace, "None", py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glLineWidth", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glLineWidth, "None", py::arg("theWidth"));
cls_OpenGl_GlCore11Fwd.def("glPolygonOffset", (void (OpenGl_GlCore11Fwd::*)(GLfloat, GLfloat)) &OpenGl_GlCore11Fwd::glPolygonOffset, "None", py::arg("theFactor"), py::arg("theUnits"));
cls_OpenGl_GlCore11Fwd.def("glScissor", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glScissor, "None", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_GlCore11Fwd.def("glEnable", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glEnable, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glDisable", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glDisable, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glIsEnabled", (GLboolean (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glIsEnabled, "None", py::arg("theCap"));
cls_OpenGl_GlCore11Fwd.def("glGetBooleanv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLboolean *)) &OpenGl_GlCore11Fwd::glGetBooleanv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetFloatv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLfloat *)) &OpenGl_GlCore11Fwd::glGetFloatv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetIntegerv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint *)) &OpenGl_GlCore11Fwd::glGetIntegerv, "None", py::arg("theParamName"), py::arg("theValues"));
cls_OpenGl_GlCore11Fwd.def("glGetError", (GLenum (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glGetError, "None");
cls_OpenGl_GlCore11Fwd.def("glGetString", (const GLubyte * (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glGetString, "None", py::arg("theName"));
cls_OpenGl_GlCore11Fwd.def("glFinish", (void (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glFinish, "None");
cls_OpenGl_GlCore11Fwd.def("glFlush", (void (OpenGl_GlCore11Fwd::*)()) &OpenGl_GlCore11Fwd::glFlush, "None");
cls_OpenGl_GlCore11Fwd.def("glHint", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum)) &OpenGl_GlCore11Fwd::glHint, "None", py::arg("theTarget"), py::arg("theMode"));
cls_OpenGl_GlCore11Fwd.def("glClearDepth", (void (OpenGl_GlCore11Fwd::*)(GLclampd)) &OpenGl_GlCore11Fwd::glClearDepth, "", py::arg("theDepth"));
cls_OpenGl_GlCore11Fwd.def("glClearDepthf", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glClearDepthf, "None", py::arg("theDepth"));
cls_OpenGl_GlCore11Fwd.def("glDepthFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum)) &OpenGl_GlCore11Fwd::glDepthFunc, "None", py::arg("theFunc"));
cls_OpenGl_GlCore11Fwd.def("glDepthMask", (void (OpenGl_GlCore11Fwd::*)(GLboolean)) &OpenGl_GlCore11Fwd::glDepthMask, "None", py::arg("theFlag"));
cls_OpenGl_GlCore11Fwd.def("glDepthRange", (void (OpenGl_GlCore11Fwd::*)(GLclampd, GLclampd)) &OpenGl_GlCore11Fwd::glDepthRange, "None", py::arg("theNearValue"), py::arg("theFarValue"));
cls_OpenGl_GlCore11Fwd.def("glDepthRangef", (void (OpenGl_GlCore11Fwd::*)(GLfloat, GLfloat)) &OpenGl_GlCore11Fwd::glDepthRangef, "None", py::arg("theNearValue"), py::arg("theFarValue"));
cls_OpenGl_GlCore11Fwd.def("glViewport", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glViewport, "", py::arg("theX"), py::arg("theY"), py::arg("theWidth"), py::arg("theHeight"));
cls_OpenGl_GlCore11Fwd.def("glDrawArrays", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLsizei)) &OpenGl_GlCore11Fwd::glDrawArrays, "", py::arg("theMode"), py::arg("theFirst"), py::arg("theCount"));
cls_OpenGl_GlCore11Fwd.def("glDrawElements", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLsizei, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glDrawElements, "None", py::arg("theMode"), py::arg("theCount"), py::arg("theType"), py::arg("theIndices"));
cls_OpenGl_GlCore11Fwd.def("glPixelStorei", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint)) &OpenGl_GlCore11Fwd::glPixelStorei, "", py::arg("theParamName"), py::arg("theParam"));
cls_OpenGl_GlCore11Fwd.def("glReadPixels", (void (OpenGl_GlCore11Fwd::*)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *)) &OpenGl_GlCore11Fwd::glReadPixels, "None", py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glStencilFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLuint)) &OpenGl_GlCore11Fwd::glStencilFunc, "", py::arg("func"), py::arg("ref"), py::arg("mask"));
cls_OpenGl_GlCore11Fwd.def("glStencilMask", (void (OpenGl_GlCore11Fwd::*)(GLuint)) &OpenGl_GlCore11Fwd::glStencilMask, "None", py::arg("mask"));
cls_OpenGl_GlCore11Fwd.def("glStencilOp", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLenum)) &OpenGl_GlCore11Fwd::glStencilOp, "None", py::arg("fail"), py::arg("zfail"), py::arg("zpass"));
cls_OpenGl_GlCore11Fwd.def("glClearStencil", (void (OpenGl_GlCore11Fwd::*)(GLint)) &OpenGl_GlCore11Fwd::glClearStencil, "None", py::arg("s"));
cls_OpenGl_GlCore11Fwd.def("glTexParameterf", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLfloat)) &OpenGl_GlCore11Fwd::glTexParameterf, "", py::arg("target"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11Fwd.def("glTexParameteri", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLint)) &OpenGl_GlCore11Fwd::glTexParameteri, "None", py::arg("target"), py::arg("pname"), py::arg("param"));
cls_OpenGl_GlCore11Fwd.def("glTexParameterfv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, const GLfloat *)) &OpenGl_GlCore11Fwd::glTexParameterfv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glTexParameteriv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, const GLint *)) &OpenGl_GlCore11Fwd::glTexParameteriv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glGetTexParameterfv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLfloat *)) &OpenGl_GlCore11Fwd::glGetTexParameterfv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glGetTexParameteriv", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLenum, GLint *)) &OpenGl_GlCore11Fwd::glGetTexParameteriv, "None", py::arg("target"), py::arg("pname"), py::arg("params"));
cls_OpenGl_GlCore11Fwd.def("glTexImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexImage2D, "None", py::arg("target"), py::arg("level"), py::arg("internalFormat"), py::arg("width"), py::arg("height"), py::arg("border"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glGenTextures", (void (OpenGl_GlCore11Fwd::*)(GLsizei, GLuint *)) &OpenGl_GlCore11Fwd::glGenTextures, "None", py::arg("n"), py::arg("textures"));
cls_OpenGl_GlCore11Fwd.def("glDeleteTextures", (void (OpenGl_GlCore11Fwd::*)(GLsizei, const GLuint *)) &OpenGl_GlCore11Fwd::glDeleteTextures, "None", py::arg("n"), py::arg("textures"));
cls_OpenGl_GlCore11Fwd.def("glBindTexture", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLuint)) &OpenGl_GlCore11Fwd::glBindTexture, "None", py::arg("target"), py::arg("texture"));
cls_OpenGl_GlCore11Fwd.def("glIsTexture", (GLboolean (OpenGl_GlCore11Fwd::*)(GLuint)) &OpenGl_GlCore11Fwd::glIsTexture, "None", py::arg("texture"));
cls_OpenGl_GlCore11Fwd.def("glTexSubImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexSubImage2D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("yoffset"), py::arg("width"), py::arg("height"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint)) &OpenGl_GlCore11Fwd::glCopyTexImage2D, "None", py::arg("target"), py::arg("level"), py::arg("internalformat"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"), py::arg("border"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexSubImage2D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei)) &OpenGl_GlCore11Fwd::glCopyTexSubImage2D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("yoffset"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("height"));
cls_OpenGl_GlCore11Fwd.def("glTexImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexImage1D, "None", py::arg("target"), py::arg("level"), py::arg("internalFormat"), py::arg("width"), py::arg("border"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glTexSubImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *)) &OpenGl_GlCore11Fwd::glTexSubImage1D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("width"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint)) &OpenGl_GlCore11Fwd::glCopyTexImage1D, "None", py::arg("target"), py::arg("level"), py::arg("internalformat"), py::arg("x"), py::arg("y"), py::arg("width"), py::arg("border"));
cls_OpenGl_GlCore11Fwd.def("glCopyTexSubImage1D", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLint, GLint, GLint, GLsizei)) &OpenGl_GlCore11Fwd::glCopyTexSubImage1D, "None", py::arg("target"), py::arg("level"), py::arg("xoffset"), py::arg("x"), py::arg("y"), py::arg("width"));
cls_OpenGl_GlCore11Fwd.def("glGetTexImage", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLint, GLenum, GLenum, GLvoid *)) &OpenGl_GlCore11Fwd::glGetTexImage, "None", py::arg("target"), py::arg("level"), py::arg("format"), py::arg("type"), py::arg("pixels"));
cls_OpenGl_GlCore11Fwd.def("glAlphaFunc", (void (OpenGl_GlCore11Fwd::*)(GLenum, GLclampf)) &OpenGl_GlCore11Fwd::glAlphaFunc, "None", py::arg("theFunc"), py::arg("theRef"));
cls_OpenGl_GlCore11Fwd.def("glPointSize", (void (OpenGl_GlCore11Fwd::*)(GLfloat)) &OpenGl_GlCore11Fwd::glPointSize, "None", py::arg("theSize"));

// Enums

}