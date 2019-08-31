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
#include <Geom2dToIGES_Geom2dEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2dToIGES_Geom2dCurve.hxx>
#include <IGESGeom_Point.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Geom2dToIGES_Geom2dPoint.hxx>
#include <IGESGeom_Direction.hxx>
#include <Geom2d_Vector.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <Geom2d_Direction.hxx>
#include <Geom2dToIGES_Geom2dVector.hxx>

PYBIND11_MODULE(Geom2dToIGES, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.IGESData");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.IGESGeom");

// CLASS: GEOM2DTOIGES_GEOM2DENTITY
py::class_<Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dEntity(mod, "Geom2dToIGES_Geom2dEntity", "provides methods to transfer Geom2d entity from CASCADE to IGES.");

// Constructors
cls_Geom2dToIGES_Geom2dEntity.def(py::init<>());
cls_Geom2dToIGES_Geom2dEntity.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("GE"));

// Methods
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dEntity::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dEntity::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dEntity::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dEntity::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dEntity::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dEntity.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dEntity::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dEntity.def("SetModel", (void (Geom2dToIGES_Geom2dEntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &Geom2dToIGES_Geom2dEntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
cls_Geom2dToIGES_Geom2dEntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (Geom2dToIGES_Geom2dEntity::*)() const) &Geom2dToIGES_Geom2dEntity::GetModel, "Returns the value of 'TheModel'");
cls_Geom2dToIGES_Geom2dEntity.def("SetUnit", (void (Geom2dToIGES_Geom2dEntity::*)(const Standard_Real)) &Geom2dToIGES_Geom2dEntity::SetUnit, "Sets the value of the UnitFlag", py::arg("unit"));
cls_Geom2dToIGES_Geom2dEntity.def("GetUnit", (Standard_Real (Geom2dToIGES_Geom2dEntity::*)() const) &Geom2dToIGES_Geom2dEntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in millimeters.");

// CLASS: GEOM2DTOIGES_GEOM2DCURVE
py::class_<Geom2dToIGES_Geom2dCurve, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dCurve(mod, "Geom2dToIGES_Geom2dCurve", "This class implements the transfer of the Curve Entity from Geom2d To IGES. These can be : Curve . BoundedCurve * BSplineCurve * BezierCurve * TrimmedCurve . Conic * Circle * Ellipse * Hyperbloa * Line * Parabola . OffsetCurve");

// Constructors
cls_Geom2dToIGES_Geom2dCurve.def(py::init<>());
cls_Geom2dToIGES_Geom2dCurve.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Methods
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dCurve::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dCurve::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dCurve::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dCurve::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dCurve.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dCurve.def("Transfer2dCurve", (opencascade::handle<IGESData_IGESEntity> (Geom2dToIGES_Geom2dCurve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &Geom2dToIGES_Geom2dCurve::Transfer2dCurve, "Transfert an Entity from Geom2d to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));

// CLASS: GEOM2DTOIGES_GEOM2DPOINT
py::class_<Geom2dToIGES_Geom2dPoint, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dPoint(mod, "Geom2dToIGES_Geom2dPoint", "This class implements the transfer of the Point Entity from Geom2d to IGES . These are : . 2dPoint * 2dCartesianPoint");

// Constructors
cls_Geom2dToIGES_Geom2dPoint.def(py::init<>());
cls_Geom2dToIGES_Geom2dPoint.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Methods
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dPoint::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dPoint::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dPoint::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dPoint::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dPoint::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dPoint.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dPoint::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_Point> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a Point from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_CartesianPoint> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a CartesianPoint from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

// CLASS: GEOM2DTOIGES_GEOM2DVECTOR
py::class_<Geom2dToIGES_Geom2dVector, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dVector(mod, "Geom2dToIGES_Geom2dVector", "This class implements the transfer of the Vector from Geom2d to IGES . These can be : . Vector * Direction * VectorWithMagnitude");

// Constructors
cls_Geom2dToIGES_Geom2dVector.def(py::init<>());
cls_Geom2dToIGES_Geom2dVector.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));

// Methods
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dVector::operator new, "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete_", (void (*)(void *)) &Geom2dToIGES_Geom2dVector::operator delete, "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new[]_", (void * (*)(size_t)) &Geom2dToIGES_Geom2dVector::operator new[], "None", py::arg("theSize"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete[]_", (void (*)(void *)) &Geom2dToIGES_Geom2dVector::operator delete[], "None", py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator new_", (void * (*)(size_t, void *)) &Geom2dToIGES_Geom2dVector::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Geom2dToIGES_Geom2dVector.def_static("operator delete_", (void (*)(void *, void *)) &Geom2dToIGES_Geom2dVector::operator delete, "None", py::arg(""), py::arg(""));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomVector(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_VectorWithMagnitude> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));
cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Direction> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));


}
