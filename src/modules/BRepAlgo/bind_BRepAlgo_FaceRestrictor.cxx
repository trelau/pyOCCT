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
#include <TopoDS_Face.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopTools_ListOfShape.hxx>
#include <TopTools_DataMapOfShapeListOfShape.hxx>
#include <BRepAlgo_FaceRestrictor.hxx>

void bind_BRepAlgo_FaceRestrictor(py::module &mod){

py::class_<BRepAlgo_FaceRestrictor, std::unique_ptr<BRepAlgo_FaceRestrictor>> cls_BRepAlgo_FaceRestrictor(mod, "BRepAlgo_FaceRestrictor", "Builds all the faces limited with a set of non jointing and planars wires. if <ControlOrientation> is false The Wires must have correct orientations. Sinon orientation des wires de telle sorte que les faces ne soient pas infinies et qu'elles soient disjointes.");

// Constructors
cls_BRepAlgo_FaceRestrictor.def(py::init<>());

// Fields

// Methods
// cls_BRepAlgo_FaceRestrictor.def_static("operator new_", (void * (*)(size_t)) &BRepAlgo_FaceRestrictor::operator new, "None", py::arg("theSize"));
// cls_BRepAlgo_FaceRestrictor.def_static("operator delete_", (void (*)(void *)) &BRepAlgo_FaceRestrictor::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgo_FaceRestrictor.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgo_FaceRestrictor::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgo_FaceRestrictor.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgo_FaceRestrictor::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgo_FaceRestrictor.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgo_FaceRestrictor::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgo_FaceRestrictor.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgo_FaceRestrictor::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgo_FaceRestrictor.def("Init", [](BRepAlgo_FaceRestrictor &self, const TopoDS_Face & a0) -> void { return self.Init(a0); });
cls_BRepAlgo_FaceRestrictor.def("Init", [](BRepAlgo_FaceRestrictor &self, const TopoDS_Face & a0, const Standard_Boolean a1) -> void { return self.Init(a0, a1); });
cls_BRepAlgo_FaceRestrictor.def("Init", (void (BRepAlgo_FaceRestrictor::*)(const TopoDS_Face &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgo_FaceRestrictor::Init, "the surface of <F> will be the the surface of each new faces built. <Proj> is used to update pcurves on edges if necessary. See Add().", py::arg("F"), py::arg("Proj"), py::arg("ControlOrientation"));
cls_BRepAlgo_FaceRestrictor.def("Add", (void (BRepAlgo_FaceRestrictor::*)(TopoDS_Wire &)) &BRepAlgo_FaceRestrictor::Add, "Add the wire <W> to the set of wires.", py::arg("W"));
cls_BRepAlgo_FaceRestrictor.def("Clear", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Clear, "Removes all the Wires");
cls_BRepAlgo_FaceRestrictor.def("Perform", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Perform, "Evaluate all the faces limited by the set of Wires.");
cls_BRepAlgo_FaceRestrictor.def("IsDone", (Standard_Boolean (BRepAlgo_FaceRestrictor::*)() const) &BRepAlgo_FaceRestrictor::IsDone, "None");
cls_BRepAlgo_FaceRestrictor.def("More", (Standard_Boolean (BRepAlgo_FaceRestrictor::*)() const) &BRepAlgo_FaceRestrictor::More, "None");
cls_BRepAlgo_FaceRestrictor.def("Next", (void (BRepAlgo_FaceRestrictor::*)()) &BRepAlgo_FaceRestrictor::Next, "None");
cls_BRepAlgo_FaceRestrictor.def("Current", (TopoDS_Face (BRepAlgo_FaceRestrictor::*)() const) &BRepAlgo_FaceRestrictor::Current, "None");

// Enums

}