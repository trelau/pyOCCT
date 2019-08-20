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
#include <TopoDS_Vertex.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Edge.hxx>
#include <TopAbs_Orientation.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <ChFiDS_CommonPoint.hxx>

void bind_ChFiDS_CommonPoint(py::module &mod){

py::class_<ChFiDS_CommonPoint, std::unique_ptr<ChFiDS_CommonPoint>> cls_ChFiDS_CommonPoint(mod, "ChFiDS_CommonPoint", "point start/end of fillet common to 2 adjacent filets and to an edge on one of 2 faces participating in the construction of the fillet");

// Constructors
cls_ChFiDS_CommonPoint.def(py::init<>());

// Fields

// Methods
// cls_ChFiDS_CommonPoint.def_static("operator new_", (void * (*)(size_t)) &ChFiDS_CommonPoint::operator new, "None", py::arg("theSize"));
// cls_ChFiDS_CommonPoint.def_static("operator delete_", (void (*)(void *)) &ChFiDS_CommonPoint::operator delete, "None", py::arg("theAddress"));
// cls_ChFiDS_CommonPoint.def_static("operator new[]_", (void * (*)(size_t)) &ChFiDS_CommonPoint::operator new[], "None", py::arg("theSize"));
// cls_ChFiDS_CommonPoint.def_static("operator delete[]_", (void (*)(void *)) &ChFiDS_CommonPoint::operator delete[], "None", py::arg("theAddress"));
// cls_ChFiDS_CommonPoint.def_static("operator new_", (void * (*)(size_t, void *)) &ChFiDS_CommonPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ChFiDS_CommonPoint.def_static("operator delete_", (void (*)(void *, void *)) &ChFiDS_CommonPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_ChFiDS_CommonPoint.def("Reset", (void (ChFiDS_CommonPoint::*)()) &ChFiDS_CommonPoint::Reset, "default value for all fields");
cls_ChFiDS_CommonPoint.def("SetVertex", (void (ChFiDS_CommonPoint::*)(const TopoDS_Vertex &)) &ChFiDS_CommonPoint::SetVertex, "Sets the values of a point which is a vertex on the initial facet of restriction of one of the surface.", py::arg("V"));
cls_ChFiDS_CommonPoint.def("SetArc", (void (ChFiDS_CommonPoint::*)(const Standard_Real, const TopoDS_Edge &, const Standard_Real, const TopAbs_Orientation)) &ChFiDS_CommonPoint::SetArc, "Sets the values of a point which is on the arc A, at parameter Param.", py::arg("Tol"), py::arg("A"), py::arg("Param"), py::arg("TArc"));
cls_ChFiDS_CommonPoint.def("SetParameter", (void (ChFiDS_CommonPoint::*)(const Standard_Real)) &ChFiDS_CommonPoint::SetParameter, "Sets the value of the parameter on the spine", py::arg("Param"));
cls_ChFiDS_CommonPoint.def("SetPoint", (void (ChFiDS_CommonPoint::*)(const gp_Pnt &)) &ChFiDS_CommonPoint::SetPoint, "Set the 3d point for a commonpoint that is not a vertex or on an arc.", py::arg("Point"));
cls_ChFiDS_CommonPoint.def("SetVector", (void (ChFiDS_CommonPoint::*)(const gp_Vec &)) &ChFiDS_CommonPoint::SetVector, "Set the output 3d vector", py::arg("Vector"));
cls_ChFiDS_CommonPoint.def("SetTolerance", (void (ChFiDS_CommonPoint::*)(const Standard_Real)) &ChFiDS_CommonPoint::SetTolerance, "This method set the fuzziness on the point.", py::arg("Tol"));
cls_ChFiDS_CommonPoint.def("Tolerance", (Standard_Real (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Tolerance, "This method returns the fuzziness on the point.");
cls_ChFiDS_CommonPoint.def("IsVertex", (Standard_Boolean (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::IsVertex, "Returns TRUE if the point is a vertex on the initial restriction facet of the surface.");
cls_ChFiDS_CommonPoint.def("Vertex", (const TopoDS_Vertex & (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Vertex, "Returns the information about the point when it is on the domain of the first patch, i-e when the function IsVertex returns True. Otherwise, an exception is raised.");
cls_ChFiDS_CommonPoint.def("IsOnArc", (Standard_Boolean (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::IsOnArc, "Returns TRUE if the point is a on an edge of the initial restriction facet of the surface.");
cls_ChFiDS_CommonPoint.def("Arc", (const TopoDS_Edge & (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Arc, "Returns the arc of restriction containing the vertex.");
cls_ChFiDS_CommonPoint.def("TransitionOnArc", (TopAbs_Orientation (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::TransitionOnArc, "Returns the transition of the point on the arc returned by Arc().");
cls_ChFiDS_CommonPoint.def("ParameterOnArc", (Standard_Real (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::ParameterOnArc, "Returns the parameter of the point on the arc returned by the method Arc().");
cls_ChFiDS_CommonPoint.def("Parameter", (Standard_Real (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Parameter, "Returns the parameter the paramter on the spine");
cls_ChFiDS_CommonPoint.def("Point", (const gp_Pnt & (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Point, "Returns the 3d point");
cls_ChFiDS_CommonPoint.def("HasVector", (Standard_Boolean (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::HasVector, "Returns TRUE if the output vector is stored.");
cls_ChFiDS_CommonPoint.def("Vector", (const gp_Vec & (ChFiDS_CommonPoint::*)() const) &ChFiDS_CommonPoint::Vector, "Returns the output 3d vector");

// Enums

}