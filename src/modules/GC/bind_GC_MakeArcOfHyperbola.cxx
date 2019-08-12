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
#include <gp_Hypr.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <GC_MakeArcOfHyperbola.hxx>

void bind_GC_MakeArcOfHyperbola(py::module &mod){

py::class_<GC_MakeArcOfHyperbola, std::unique_ptr<GC_MakeArcOfHyperbola, Deleter<GC_MakeArcOfHyperbola>>, GC_Root> cls_GC_MakeArcOfHyperbola(mod, "GC_MakeArcOfHyperbola", "Implements construction algorithms for an arc of hyperbola in 3D space. The result is a Geom_TrimmedCurve curve. A MakeArcOfHyperbola object provides a framework for: - defining the construction of the arc of hyperbola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed arc of hyperbola.");

// Constructors
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("Alpha1"), py::arg("Alpha2"), py::arg("Sense"));
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const gp_Pnt &, const Standard_Real, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P"), py::arg("Alpha"), py::arg("Sense"));
cls_GC_MakeArcOfHyperbola.def(py::init<const gp_Hypr &, const gp_Pnt &, const gp_Pnt &, const Standard_Boolean>(), py::arg("Hypr"), py::arg("P1"), py::arg("P2"), py::arg("Sense"));

// Fields

// Methods
// cls_GC_MakeArcOfHyperbola.def_static("operator new_", (void * (*)(size_t)) &GC_MakeArcOfHyperbola::operator new, "None", py::arg("theSize"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete_", (void (*)(void *)) &GC_MakeArcOfHyperbola::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeArcOfHyperbola::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeArcOfHyperbola::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeArcOfHyperbola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeArcOfHyperbola.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeArcOfHyperbola::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeArcOfHyperbola.def("Value", (const opencascade::handle<Geom_TrimmedCurve> & (GC_MakeArcOfHyperbola::*)() const) &GC_MakeArcOfHyperbola::Value, "Returns the constructed arc of hyperbola.");

// Enums

}