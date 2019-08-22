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
#include <TopoDS_Shape.hxx>
#include <LocOpe_SequenceOfLin.hxx>
#include <LocOpe_SequenceOfCirc.hxx>
#include <TColGeom_SequenceOfCurve.hxx>
#include <Standard_TypeDef.hxx>
#include <LocOpe_PntFace.hxx>
#include <TopAbs_Orientation.hxx>
#include <LocOpe_CSIntersector.hxx>

void bind_LocOpe_CSIntersector(py::module &mod){

py::class_<LocOpe_CSIntersector> cls_LocOpe_CSIntersector(mod, "LocOpe_CSIntersector", "This class provides the intersection between a set of axis or a circle and the faces of a shape. The intersection points are sorted in increasing parameter along each axis or circle.");

// Constructors
cls_LocOpe_CSIntersector.def(py::init<>());
cls_LocOpe_CSIntersector.def(py::init<const TopoDS_Shape &>(), py::arg("S"));

// Fields

// Methods
// cls_LocOpe_CSIntersector.def_static("operator new_", (void * (*)(size_t)) &LocOpe_CSIntersector::operator new, "None", py::arg("theSize"));
// cls_LocOpe_CSIntersector.def_static("operator delete_", (void (*)(void *)) &LocOpe_CSIntersector::operator delete, "None", py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator new[]_", (void * (*)(size_t)) &LocOpe_CSIntersector::operator new[], "None", py::arg("theSize"));
// cls_LocOpe_CSIntersector.def_static("operator delete[]_", (void (*)(void *)) &LocOpe_CSIntersector::operator delete[], "None", py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator new_", (void * (*)(size_t, void *)) &LocOpe_CSIntersector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_LocOpe_CSIntersector.def_static("operator delete_", (void (*)(void *, void *)) &LocOpe_CSIntersector::operator delete, "None", py::arg(""), py::arg(""));
cls_LocOpe_CSIntersector.def("Init", (void (LocOpe_CSIntersector::*)(const TopoDS_Shape &)) &LocOpe_CSIntersector::Init, "Performs the intersection between <Ax1 and <S>.", py::arg("S"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfLin &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Slin"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const LocOpe_SequenceOfCirc &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scir"));
cls_LocOpe_CSIntersector.def("Perform", (void (LocOpe_CSIntersector::*)(const TColGeom_SequenceOfCurve &)) &LocOpe_CSIntersector::Perform, "None", py::arg("Scur"));
cls_LocOpe_CSIntersector.def("IsDone", (Standard_Boolean (LocOpe_CSIntersector::*)() const) &LocOpe_CSIntersector::IsDone, "Returns <Standard_True> if the intersection has been done.");
cls_LocOpe_CSIntersector.def("NbPoints", (Standard_Integer (LocOpe_CSIntersector::*)(const Standard_Integer) const) &LocOpe_CSIntersector::NbPoints, "Returns the number of intersection point on the element of range <I>.", py::arg("I"));
cls_LocOpe_CSIntersector.def("Point", (const LocOpe_PntFace & (LocOpe_CSIntersector::*)(const Standard_Integer, const Standard_Integer) const) &LocOpe_CSIntersector::Point, "Returns the intersection point of range <Index> on element of range <I>. The points are sorted in increasing order of parameter along the axis.", py::arg("I"), py::arg("Index"));
cls_LocOpe_CSIntersector.def("LocalizeAfter", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Real From, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(I, From, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located after the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeBefore", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Real From, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(I, From, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located before the parameter <From>, wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("From"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeAfter", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Integer FromInd, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeAfter(I, FromInd, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located after the index <FromInd> ( >= FromInd + 1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point. (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("LocalizeBefore", [](LocOpe_CSIntersector &self, const Standard_Integer I, const Standard_Integer FromInd, const Standard_Real Tol, TopAbs_Orientation & Or, Standard_Integer & IndFrom, Standard_Integer & IndTo){ Standard_Boolean rv = self.LocalizeBefore(I, FromInd, Tol, Or, IndFrom, IndTo); return std::tuple<Standard_Boolean, Standard_Integer &, Standard_Integer &>(rv, IndFrom, IndTo); }, "On the element of range <I>, searches the first intersection point located before the index <FromInd> ( <= FromInd -1), wich orientation is not TopAbs_EXTERNAL. If found, returns <Standard_True>. <Or> contains the orientation of the point, <IndFrom> and <IndTo> represents the interval of index in the sequence of intersection point corresponding to the point (IndFrom <= IndTo). <Tol> is used to determine if 2 parameters are equal.", py::arg("I"), py::arg("FromInd"), py::arg("Tol"), py::arg("Or"), py::arg("IndFrom"), py::arg("IndTo"));
cls_LocOpe_CSIntersector.def("Destroy", (void (LocOpe_CSIntersector::*)()) &LocOpe_CSIntersector::Destroy, "None");

// Enums

}