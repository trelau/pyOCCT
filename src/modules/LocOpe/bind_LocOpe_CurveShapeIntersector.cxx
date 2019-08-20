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
#include <gp_Ax1.hxx>
#include <TopoDS_Shape.hxx>
#include <gp_Circ.hxx>
#include <Standard_TypeDef.hxx>
#include <LocOpe_PntFace.hxx>
#include <TopAbs_Orientation.hxx>
#include <LocOpe_SequenceOfPntFace.hxx>
#include <LocOpe_CurveShapeIntersector.hxx>

void bind_LocOpe_CurveShapeIntersector(py::module &mod){

py::class_<LocOpe_CurveShapeIntersector, std::unique_ptr<LocOpe_CurveShapeIntersector>> cls_LocOpe_CurveShapeIntersector(mod, "LocOpe_CurveShapeIntersector", "This class provides the intersection between an axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along the axis.");

// Constructors
cls_LocOpe_CurveShapeIntersector.def(py::init<>());
cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Ax1 &, const TopoDS_Shape &>(), py::arg("Axis"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def(py::init<const gp_Circ &, const TopoDS_Shape &>(), py::arg("C"), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_CurveShapeIntersector.def_static("operator new_", (void * (*)(size_t)) &LocOpe_CurveShapeIntersector::operator new, "None", py::arg("theSize"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete_", (void (*)(void *)) &LocOpe_CurveShapeIntersector::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_CurveShapeIntersector::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_CurveShapeIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_CurveShapeIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_CurveShapeIntersector.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_CurveShapeIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Ax1 &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("Axis"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def("Init", (void (LocOpe_CurveShapeIntersector::*)(const gp_Circ &, const TopoDS_Shape &)) &LocOpe_CurveShapeIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("C"), py::arg("S"));
cls_LocOpe_CurveShapeIntersector.def("IsDone", (Standard_Boolean (LocOpe_CurveShapeIntersector::*)() const) &LocOpe_CurveShapeIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
cls_LocOpe_CurveShapeIntersector.def("NbPoints", (Standard_Integer (LocOpe_CurveShapeIntersector::*)() const) &LocOpe_CurveShapeIntersector::NbPoints, "Returns the number of intersection point.");
cls_LocOpe_CurveShapeIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CurveShapeIntersector::*)(const Standard_Integer) const) &LocOpe_CurveShapeIntersector::Point, "Returns the intersection point of range <Index>. The points are sorted in increasing order of parameter along the axis.", py::arg("Index"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", [](LocOpe_CurveShapeIntersector &self, const Standard_Real From, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(From, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", [](LocOpe_CurveShapeIntersector &self, const Standard_Real From, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(From, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("From"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeAfter", [](LocOpe_CurveShapeIntersector &self, const Standard_Integer FromInd, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(FromInd, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CurveShapeIntersector.def("LocalizeBefore", [](LocOpe_CurveShapeIntersector &self, const Standard_Integer FromInd, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(FromInd, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "Searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo).", py::arg("FromInd"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));

// Enums

}