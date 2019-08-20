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
#include <GeomToIGES_GeomEntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BoundedCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Conic.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Hyperbola.hxx>
#include <Geom_Line.hxx>
#include <Geom_Parabola.hxx>
#include <Geom_OffsetCurve.hxx>
#include <GeomToIGES_GeomCurve.hxx>

void bind_GeomToIGES_GeomCurve(py::module &mod){

py::class_<GeomToIGES_GeomCurve, std::unique_ptr<GeomToIGES_GeomCurve>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomCurve(mod, "GeomToIGES_GeomCurve", "This class implements the transfer of the Curve Entity from Geom To IGES. These can be : Curve . BoundedCurve * BSplineCurve * BezierCurve * TrimmedCurve . Conic * Circle * Ellipse * Hyperbloa * Line * Parabola . OffsetCurve");

// Constructors
cls_GeomToIGES_GeomCurve.def(py::init<>());
cls_GeomToIGES_GeomCurve.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_GeomToIGES_GeomCurve.def_static("operator new_", (void * (*)(size_t)) &GeomToIGES_GeomCurve::operator new, "None", py::arg("theSize"));
// cls_GeomToIGES_GeomCurve.def_static("operator delete_", (void (*)(void *)) &GeomToIGES_GeomCurve::operator delete, "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomCurve.def_static("operator new[]_", (void * (*)(size_t)) &GeomToIGES_GeomCurve::operator new[], "None", py::arg("theSize"));
// cls_GeomToIGES_GeomCurve.def_static("operator delete[]_", (void (*)(void *)) &GeomToIGES_GeomCurve::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomCurve.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToIGES_GeomCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToIGES_GeomCurve.def_static("operator delete_", (void (*)(void *, void *)) &GeomToIGES_GeomCurve::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomCurve(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BoundedCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BezierCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_TrimmedCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Conic> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Ellipse> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Hyperbola> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Line> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Parabola> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_OffsetCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));

// Enums

}