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
#include <Standard_Transient.hxx>
#include <IntSurf_Allocator.hxx>
#include <Standard_TypeDef.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <IntSurf_PathPoint.hxx>
#include <gp_Vec.hxx>
#include <Standard_Handle.hxx>
#include <IntSurf_LineOn2S.hxx>
#include <IntPatch_TheIWLineOfTheIWalking.hxx>
#include <Standard_Type.hxx>
#include <IntSurf_SequenceOfCouple.hxx>

void bind_IntPatch_TheIWLineOfTheIWalking(py::module &mod){

py::class_<IntPatch_TheIWLineOfTheIWalking, opencascade::handle<IntPatch_TheIWLineOfTheIWalking>, Standard_Transient> cls_IntPatch_TheIWLineOfTheIWalking(mod, "IntPatch_TheIWLineOfTheIWalking", "None");

// Constructors
cls_IntPatch_TheIWLineOfTheIWalking.def(py::init<>());
cls_IntPatch_TheIWLineOfTheIWalking.def(py::init<const IntSurf_Allocator &>(), py::arg("theAllocator"));

// Fields

// Methods
cls_IntPatch_TheIWLineOfTheIWalking.def("Reverse", (void (IntPatch_TheIWLineOfTheIWalking::*)()) &IntPatch_TheIWLineOfTheIWalking::Reverse, "reverse the points in the line. Hasfirst, HasLast are kept.");
cls_IntPatch_TheIWLineOfTheIWalking.def("Cut", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::Cut, "Cut the line at the point of rank Index.", py::arg("Index"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddPoint", (void (IntPatch_TheIWLineOfTheIWalking::*)(const IntSurf_PntOn2S &)) &IntPatch_TheIWLineOfTheIWalking::AddPoint, "Add a point in the line.", py::arg("P"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasFirst"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirst", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirst, "None", py::arg("Closed"), py::arg("HasLast"), py::arg("Index"), py::arg("P"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusFirstLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Boolean, const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusFirstLast, "None", py::arg("Closed"), py::arg("HasFirst"), py::arg("HasLast"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddStatusLast", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean, const Standard_Integer, const IntSurf_PathPoint &)) &IntPatch_TheIWLineOfTheIWalking::AddStatusLast, "None", py::arg("HasLast"), py::arg("Index"), py::arg("P"));
cls_IntPatch_TheIWLineOfTheIWalking.def("AddIndexPassing", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::AddIndexPassing, "associer a l 'indice du point sur la ligne l'indice du point passant dans l'iterateur de depart", py::arg("Index"));
cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangentVector", (void (IntPatch_TheIWLineOfTheIWalking::*)(const gp_Vec &, const Standard_Integer)) &IntPatch_TheIWLineOfTheIWalking::SetTangentVector, "None", py::arg("V"), py::arg("Index"));
cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangencyAtBegining", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::SetTangencyAtBegining, "None", py::arg("IsTangent"));
cls_IntPatch_TheIWLineOfTheIWalking.def("SetTangencyAtEnd", (void (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Boolean)) &IntPatch_TheIWLineOfTheIWalking::SetTangencyAtEnd, "None", py::arg("IsTangent"));
cls_IntPatch_TheIWLineOfTheIWalking.def("NbPoints", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::NbPoints, "Returns the number of points of the line (including first point and end point : see HasLastPoint and HasFirstPoint).");
cls_IntPatch_TheIWLineOfTheIWalking.def("Value", (const IntSurf_PntOn2S & (IntPatch_TheIWLineOfTheIWalking::*)(const Standard_Integer) const) &IntPatch_TheIWLineOfTheIWalking::Value, "Returns the point of range Index. If index <= 0 or Index > NbPoints, an exception is raised.", py::arg("Index"));
cls_IntPatch_TheIWLineOfTheIWalking.def("Line", (const opencascade::handle<IntSurf_LineOn2S> & (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::Line, "Returns the LineOn2S contained in the walking line.");
cls_IntPatch_TheIWLineOfTheIWalking.def("IsClosed", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::IsClosed, "Returns True if the line is closed.");
cls_IntPatch_TheIWLineOfTheIWalking.def("HasFirstPoint", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::HasFirstPoint, "Returns True if the first point of the line is a marching point . when is HasFirstPoint==False ,the line begins on the natural bound of the surface.the line can be too long");
cls_IntPatch_TheIWLineOfTheIWalking.def("HasLastPoint", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::HasLastPoint, "Returns True if the end point of the line is a marching point (Point from IntWS). when is HasFirstPoint==False ,the line ends on the natural bound of the surface.the line can be too long.");
cls_IntPatch_TheIWLineOfTheIWalking.def("FirstPoint", (const IntSurf_PathPoint & (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::FirstPoint, "Returns the first point of the line when it is a marching point. An exception is raised if HasFirstPoint returns False.");
cls_IntPatch_TheIWLineOfTheIWalking.def("FirstPointIndex", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::FirstPointIndex, "Returns the Index of first point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasFirstPoint returns False.");
cls_IntPatch_TheIWLineOfTheIWalking.def("LastPoint", (const IntSurf_PathPoint & (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::LastPoint, "Returns the last point of the line when it is a marching point. An exception is raised if HasLastPoint returns False.");
cls_IntPatch_TheIWLineOfTheIWalking.def("LastPointIndex", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::LastPointIndex, "Returns the index of last point of the line when it is a marching point.This index is the index in the PointStartIterator. An exception is raised if HasLastPoint returns False.");
cls_IntPatch_TheIWLineOfTheIWalking.def("NbPassingPoint", (Standard_Integer (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::NbPassingPoint, "returns the number of points belonging to Pnts1 which are passing point.");
cls_IntPatch_TheIWLineOfTheIWalking.def("PassingPoint", [](IntPatch_TheIWLineOfTheIWalking &self, const Standard_Integer Index, Standard_Integer & IndexLine, Standard_Integer & IndexPnts){ self.PassingPoint(Index, IndexLine, IndexPnts); return std::tuple<Standard_Integer &, Standard_Integer &>(IndexLine, IndexPnts); }, "returns the index of the point belonging to the line which is associated to the passing point belonging to Pnts1 an exception is raised if Index > NbPassingPoint()", py::arg("Index"), py::arg("IndexLine"), py::arg("IndexPnts"));
cls_IntPatch_TheIWLineOfTheIWalking.def("TangentVector", [](IntPatch_TheIWLineOfTheIWalking &self, Standard_Integer & Index){ const gp_Vec & rv = self.TangentVector(Index); return std::tuple<const gp_Vec &, Standard_Integer &>(rv, Index); }, "None", py::arg("Index"));
cls_IntPatch_TheIWLineOfTheIWalking.def("IsTangentAtBegining", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::IsTangentAtBegining, "None");
cls_IntPatch_TheIWLineOfTheIWalking.def("IsTangentAtEnd", (Standard_Boolean (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::IsTangentAtEnd, "None");
cls_IntPatch_TheIWLineOfTheIWalking.def_static("get_type_name_", (const char * (*)()) &IntPatch_TheIWLineOfTheIWalking::get_type_name, "None");
cls_IntPatch_TheIWLineOfTheIWalking.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IntPatch_TheIWLineOfTheIWalking::get_type_descriptor, "None");
cls_IntPatch_TheIWLineOfTheIWalking.def("DynamicType", (const opencascade::handle<Standard_Type> & (IntPatch_TheIWLineOfTheIWalking::*)() const) &IntPatch_TheIWLineOfTheIWalking::DynamicType, "None");

// Enums

}