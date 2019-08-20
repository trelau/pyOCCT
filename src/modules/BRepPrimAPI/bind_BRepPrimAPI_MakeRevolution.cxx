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
#include <BRepPrimAPI_MakeOneAxis.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax2.hxx>
#include <BRepPrim_Revolution.hxx>
#include <BRepPrimAPI_MakeRevolution.hxx>

void bind_BRepPrimAPI_MakeRevolution(py::module &mod){

py::class_<BRepPrimAPI_MakeRevolution, std::unique_ptr<BRepPrimAPI_MakeRevolution>, BRepPrimAPI_MakeOneAxis> cls_BRepPrimAPI_MakeRevolution(mod, "BRepPrimAPI_MakeRevolution", "Describes functions to build revolved shapes. A MakeRevolution object provides a framework for: - defining the construction of a revolved shape, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &>(), py::arg("Meridian"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Meridian"), py::arg("angle"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"), py::arg("angle"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &>(), py::arg("Axes"), py::arg("Meridian"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("angle"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"));
cls_BRepPrimAPI_MakeRevolution.def(py::init<const gp_Ax2 &, const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("Meridian"), py::arg("VMin"), py::arg("VMax"), py::arg("angle"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeRevolution.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeRevolution::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeRevolution.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeRevolution::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevolution.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeRevolution::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeRevolution.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeRevolution::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevolution.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeRevolution::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeRevolution.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeRevolution::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeRevolution.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeRevolution::*)()) &BRepPrimAPI_MakeRevolution::OneAxis, "Returns the algorithm.");
cls_BRepPrimAPI_MakeRevolution.def("Revolution", (BRepPrim_Revolution & (BRepPrimAPI_MakeRevolution::*)()) &BRepPrimAPI_MakeRevolution::Revolution, "Returns the algorithm.");

// Enums

}