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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Hyperbola.hxx>
#include <GC_MakeHyperbola.hxx>

void bind_GC_MakeHyperbola(py::module &mod){

py::class_<GC_MakeHyperbola, std::unique_ptr<GC_MakeHyperbola, Deleter<GC_MakeHyperbola>>, GC_Root> cls_GC_MakeHyperbola(mod, "GC_MakeHyperbola", "This class implements construction algorithms for a hyperbola in 3D space. The result is a Geom_Hyperbola hyperbola. A MakeHyperbola object provides a framework for: - defining the construction of the hyperbola, - implementing the construction algorithm, and - consulting the results. In particular, the Value function returns the constructed hyperbola. To define the main branch of an hyperbola. The parameterization range is ]-infinite,+infinite[ It is possible to get the other branch and the two conjugate branches of the main branch.");

// Constructors
cls_GC_MakeHyperbola.def(py::init<const gp_Hypr &>(), py::arg("H"));
cls_GC_MakeHyperbola.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_GC_MakeHyperbola.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("S1"), py::arg("S2"), py::arg("Center"));

// Fields

// Methods
// cls_GC_MakeHyperbola.def_static("operator new_", (void * (*)(size_t)) &GC_MakeHyperbola::operator new, "None", py::arg("theSize"));
// cls_GC_MakeHyperbola.def_static("operator delete_", (void (*)(void *)) &GC_MakeHyperbola::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeHyperbola::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeHyperbola.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeHyperbola::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeHyperbola::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeHyperbola.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeHyperbola::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeHyperbola.def("Value", (const opencascade::handle<Geom_Hyperbola> & (GC_MakeHyperbola::*)() const) &GC_MakeHyperbola::Value, "Returns the constructed hyperbola. Exceptions StdFail_NotDone if no hyperbola is constructed.");

// Enums

}