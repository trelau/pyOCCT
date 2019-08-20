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
#include <GC_Root.hxx>
#include <Standard.hxx>
#include <gp_Elips.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeArcOfEllipse.hxx>

void bind_GC_MakeArcOfEllipse(py::module &mod){

py::class_<GC_MakeArcOfEllipse, std::unique_ptr<GC_MakeArcOfEllipse>, GC_Root> cls_GC_MakeArcOfEllipse(mod, "GC_MakeArcOfEllipse", "Implements construction algorithms for an arc of ellipse in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfEllipse object provides a framework for: - defining the construction of the arc of ellipse, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of ellipse.");

// Constructors
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Elips"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfEllipse.def(py::init<const gp_Elips &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Elips"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));

// Fields

// Methods
// cls_GC_MakeArcOfEllipse.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfEllipse::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfEllipse::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfEllipse::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfEllipse::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfEllipse::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfEllipse.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfEllipse::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfEllipse.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfEllipse::*)() const) &GC_MakeArcOfEllipse::Value, "Returns the constructed arc of ellipse.");

// Enums

}