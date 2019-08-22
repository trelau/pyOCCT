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
#include <gp_Pnt.hxx>
#include <BRepExtrema_SupportType.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <BRepExtrema_SolutionElem.hxx>

void bind_BRepExtrema_SolutionElem(py::module &mod){

py::class_<BRepExtrema_SolutionElem> cls_BRepExtrema_SolutionElem(mod, "BRepExtrema_SolutionElem", "This class is used to store information relative to the minimum distance between two shapes.");

// Constructors
cls_BRepExtrema_SolutionElem.def(py::init<>());
cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Vertex &>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theVertex"));
cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Edge &, const Standard_Real>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theEdge"), py::arg("theParam"));
cls_BRepExtrema_SolutionElem.def(py::init<const Standard_Real, const gp_Pnt &, const BRepExtrema_SupportType, const TopoDS_Face &, const Standard_Real, const Standard_Real>(), py::arg("theDist"), py::arg("thePoint"), py::arg("theSolType"), py::arg("theFace"), py::arg("theU"), py::arg("theV"));

// Fields

// Methods
// cls_BRepExtrema_SolutionElem.def_static("operator new_", (void * (*)(size_t)) &BRepExtrema_SolutionElem::operator new, "None", py::arg("theSize"));
// cls_BRepExtrema_SolutionElem.def_static("operator delete_", (void (*)(void *)) &BRepExtrema_SolutionElem::operator delete, "None", py::arg("theAddress"));
// cls_BRepExtrema_SolutionElem.def_static("operator new[]_", (void * (*)(size_t)) &BRepExtrema_SolutionElem::operator new[], "None", py::arg("theSize"));
// cls_BRepExtrema_SolutionElem.def_static("operator delete[]_", (void (*)(void *)) &BRepExtrema_SolutionElem::operator delete[], "None", py::arg("theAddress"));
// cls_BRepExtrema_SolutionElem.def_static("operator new_", (void * (*)(size_t, void *)) &BRepExtrema_SolutionElem::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepExtrema_SolutionElem.def_static("operator delete_", (void (*)(void *, void *)) &BRepExtrema_SolutionElem::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepExtrema_SolutionElem.def("Dist", (Standard_Real (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::Dist, "Returns the value of the minimum distance.");
cls_BRepExtrema_SolutionElem.def("Point", (const gp_Pnt & (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::Point, "Returns the solution point.");
cls_BRepExtrema_SolutionElem.def("SupportKind", (BRepExtrema_SupportType (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::SupportKind, "Returns the Support type: IsVertex => The solution is a vertex. IsOnEdge => The solution belongs to an Edge. IsInFace => The solution is inside a Face.");
cls_BRepExtrema_SolutionElem.def("Vertex", (const TopoDS_Vertex & (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::Vertex, "Returns the vertex if the solution is a Vertex.");
cls_BRepExtrema_SolutionElem.def("Edge", (const TopoDS_Edge & (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::Edge, "Returns the vertex if the solution is an Edge.");
cls_BRepExtrema_SolutionElem.def("Face", (const TopoDS_Face & (BRepExtrema_SolutionElem::*)() const) &BRepExtrema_SolutionElem::Face, "Returns the vertex if the solution is an Face.");
cls_BRepExtrema_SolutionElem.def("EdgeParameter", [](BRepExtrema_SolutionElem &self, Standard_Real & theParam){ self.EdgeParameter(theParam); return theParam; }, "Returns the parameter value if the solution is on Edge.", py::arg("theParam"));
cls_BRepExtrema_SolutionElem.def("FaceParameter", [](BRepExtrema_SolutionElem &self, Standard_Real & theU, Standard_Real & theV){ self.FaceParameter(theU, theV); return std::tuple<Standard_Real &, Standard_Real &>(theU, theV); }, "Returns the parameters U and V if the solution is in a Face.", py::arg("theU"), py::arg("theV"));

// Enums

}