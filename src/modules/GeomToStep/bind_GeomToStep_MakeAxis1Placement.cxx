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
#include <GeomToStep_Root.hxx>
#include <Standard.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2d.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Geom2d_AxisPlacement.hxx>
#include <StepGeom_Axis1Placement.hxx>
#include <GeomToStep_MakeAxis1Placement.hxx>

void bind_GeomToStep_MakeAxis1Placement(py::module &mod){

py::class_<GeomToStep_MakeAxis1Placement, std::unique_ptr<GeomToStep_MakeAxis1Placement, Deleter<GeomToStep_MakeAxis1Placement>>, GeomToStep_Root> cls_GeomToStep_MakeAxis1Placement(mod, "GeomToStep_MakeAxis1Placement", "This class implements the mapping between classes Axis1Placement from Geom and Ax1 from gp, and the class Axis1Placement from StepGeom which describes an Axis1Placement from Prostep.");

// Constructors
cls_GeomToStep_MakeAxis1Placement.def(py::init<const gp_Ax1 &>(), py::arg("A"));
cls_GeomToStep_MakeAxis1Placement.def(py::init<const gp_Ax2d &>(), py::arg("A"));
cls_GeomToStep_MakeAxis1Placement.def(py::init<const opencascade::handle<Geom_Axis1Placement> &>(), py::arg("A"));
cls_GeomToStep_MakeAxis1Placement.def(py::init<const opencascade::handle<Geom2d_AxisPlacement> &>(), py::arg("A"));

// Fields

// Methods
// cls_GeomToStep_MakeAxis1Placement.def_static("operator new_", (void * (*)(size_t)) &GeomToStep_MakeAxis1Placement::operator new, "None", py::arg("theSize"));
// cls_GeomToStep_MakeAxis1Placement.def_static("operator delete_", (void (*)(void *)) &GeomToStep_MakeAxis1Placement::operator delete, "None", py::arg("theAddress"));
// cls_GeomToStep_MakeAxis1Placement.def_static("operator new[]_", (void * (*)(size_t)) &GeomToStep_MakeAxis1Placement::operator new[], "None", py::arg("theSize"));
// cls_GeomToStep_MakeAxis1Placement.def_static("operator delete[]_", (void (*)(void *)) &GeomToStep_MakeAxis1Placement::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToStep_MakeAxis1Placement.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToStep_MakeAxis1Placement::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToStep_MakeAxis1Placement.def_static("operator delete_", (void (*)(void *, void *)) &GeomToStep_MakeAxis1Placement::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToStep_MakeAxis1Placement.def("Value", (const opencascade::handle<StepGeom_Axis1Placement> & (GeomToStep_MakeAxis1Placement::*)() const) &GeomToStep_MakeAxis1Placement::Value, "None");

// Enums

}