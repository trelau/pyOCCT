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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <TopTools_HSequenceOfShape.hxx>
#include <TCollection_AsciiString.hxx>
#include <XSControl_FuncShape.hxx>

void bind_XSControl_FuncShape(py::module &mod){

py::class_<XSControl_FuncShape> cls_XSControl_FuncShape(mod, "XSControl_FuncShape", "Defines additionnal commands for XSControl to : - control of initialisation (xinit, xnorm, newmodel) - analyse of the result of a transfer (recorded in a TransientProcess for Read, FinderProcess for Write) : statistics, various lists (roots,complete,abnormal), what about one specific entity, producing a model with the abnormal result");

// Constructors

// Fields

// Methods
// cls_XSControl_FuncShape.def_static("operator new_", (void * (*)(size_t)) &XSControl_FuncShape::operator new, "None", py::arg("theSize"));
// cls_XSControl_FuncShape.def_static("operator delete_", (void (*)(void *)) &XSControl_FuncShape::operator delete, "None", py::arg("theAddress"));
// cls_XSControl_FuncShape.def_static("operator new[]_", (void * (*)(size_t)) &XSControl_FuncShape::operator new[], "None", py::arg("theSize"));
// cls_XSControl_FuncShape.def_static("operator delete[]_", (void (*)(void *)) &XSControl_FuncShape::operator delete[], "None", py::arg("theAddress"));
// cls_XSControl_FuncShape.def_static("operator new_", (void * (*)(size_t, void *)) &XSControl_FuncShape::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XSControl_FuncShape.def_static("operator delete_", (void (*)(void *, void *)) &XSControl_FuncShape::operator delete, "None", py::arg(""), py::arg(""));
cls_XSControl_FuncShape.def_static("Init_", (void (*)()) &XSControl_FuncShape::Init, "Defines and loads all functions which work on shapes for XSControl (as ActFunc)");
cls_XSControl_FuncShape.def_static("MoreShapes_", (Standard_Integer (*)(const opencascade::handle<XSControl_WorkSession> &, opencascade::handle<TopTools_HSequenceOfShape> &, const Standard_CString)) &XSControl_FuncShape::MoreShapes, "Analyses a name as designating Shapes from a Vars or from XSTEP transfer (last Transfer on Reading). <name> can be : '*' : all the root shapes produced by last Transfer (Read) i.e. considers roots of the TransientProcess a name : a name of a variable DRAW", py::arg("session"), py::arg("list"), py::arg("name"));
cls_XSControl_FuncShape.def_static("FileAndVar_", (Standard_Boolean (*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_CString, const Standard_CString, const Standard_CString, TCollection_AsciiString &, TCollection_AsciiString &)) &XSControl_FuncShape::FileAndVar, "Analyses given file name and variable name, with a default name for variables. Returns resulting file name and variable name plus status 'file to read'(True) or 'already read'(False) In the latter case, empty resfile means no file available", py::arg("session"), py::arg("file"), py::arg("var"), py::arg("def"), py::arg("resfile"), py::arg("resvar"));

// Enums

}