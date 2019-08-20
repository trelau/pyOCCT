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
#include <Graphic3d_Vertex.hxx>
#include <Standard_TypeDef.hxx>

void bind_Graphic3d_Vertex(py::module &mod){

py::class_<Graphic3d_Vertex, std::unique_ptr<Graphic3d_Vertex>> cls_Graphic3d_Vertex(mod, "Graphic3d_Vertex", "This class represents a graphical 3D point.");

// Constructors
cls_Graphic3d_Vertex.def(py::init<>());
cls_Graphic3d_Vertex.def(py::init<const Graphic3d_Vertex &>(), py::arg("thePoint"));
cls_Graphic3d_Vertex.def(py::init<const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_Vertex.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theX"), py::arg("theY"), py::arg("theZ"));

// Fields
// cls_Graphic3d_Vertex.def_readwrite("xyz", &Graphic3d_Vertex::xyz, "None");

// Methods
// cls_Graphic3d_Vertex.def_static("operator new_", (void * (*)(size_t)) &Graphic3d_Vertex::operator new, "None", py::arg("theSize"));
// cls_Graphic3d_Vertex.def_static("operator delete_", (void (*)(void *)) &Graphic3d_Vertex::operator delete, "None", py::arg("theAddress"));
// cls_Graphic3d_Vertex.def_static("operator new[]_", (void * (*)(size_t)) &Graphic3d_Vertex::operator new[], "None", py::arg("theSize"));
// cls_Graphic3d_Vertex.def_static("operator delete[]_", (void (*)(void *)) &Graphic3d_Vertex::operator delete[], "None", py::arg("theAddress"));
// cls_Graphic3d_Vertex.def_static("operator new_", (void * (*)(size_t, void *)) &Graphic3d_Vertex::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Graphic3d_Vertex.def_static("operator delete_", (void (*)(void *, void *)) &Graphic3d_Vertex::operator delete, "None", py::arg(""), py::arg(""));
cls_Graphic3d_Vertex.def("SetCoord", (void (Graphic3d_Vertex::*)(const Standard_ShortReal, const Standard_ShortReal, const Standard_ShortReal)) &Graphic3d_Vertex::SetCoord, "Modifies the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_Vertex.def("SetCoord", (void (Graphic3d_Vertex::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Graphic3d_Vertex::SetCoord, "Modifies the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_Vertex.def("Coord", (void (Graphic3d_Vertex::*)(Standard_ShortReal &, Standard_ShortReal &, Standard_ShortReal &) const) &Graphic3d_Vertex::Coord, "Returns the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_Vertex.def("Coord", [](Graphic3d_Vertex &self, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Coord(theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns the coordinates.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_Vertex.def("X", (Standard_ShortReal (Graphic3d_Vertex::*)() const) &Graphic3d_Vertex::X, "Returns the X coordinates.");
cls_Graphic3d_Vertex.def("Y", (Standard_ShortReal (Graphic3d_Vertex::*)() const) &Graphic3d_Vertex::Y, "Returns the Y coordinate.");
cls_Graphic3d_Vertex.def("Z", (Standard_ShortReal (Graphic3d_Vertex::*)() const) &Graphic3d_Vertex::Z, "Returns the Z coordinate.");
cls_Graphic3d_Vertex.def("Distance", (Standard_ShortReal (Graphic3d_Vertex::*)(const Graphic3d_Vertex &) const) &Graphic3d_Vertex::Distance, "Returns the distance between two points.", py::arg("theOther"));

// Enums

}