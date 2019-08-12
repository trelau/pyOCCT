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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Cylinder.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Circ.hxx>
#include <Standard_Handle.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <GC_MakeCylindricalSurface.hxx>

void bind_GC_MakeCylindricalSurface(py::module &mod){

py::class_<GC_MakeCylindricalSurface, std::unique_ptr<GC_MakeCylindricalSurface, Deleter<GC_MakeCylindricalSurface>>, GC_Root> cls_GC_MakeCylindricalSurface(mod, "GC_MakeCylindricalSurface", "This class implements the following algorithms used to create a CylindricalSurface from Geom. * Create a CylindricalSurface parallel to another and passing through a point. * Create a CylindricalSurface parallel to another at a distance <Dist>. * Create a CylindricalSurface passing through 3 points. * Create a CylindricalSurface by its axis and radius. * Create a cylindricalSurface by its circular base. The local coordinate system of the CylindricalSurface is defined with an axis placement (see class ElementarySurface).");

// Constructors
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Ax2 &, const Standard_Real>(), py::arg("A2"), py::arg("Radius"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &>(), py::arg("C"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &, const gp_Pnt &>(), py::arg("Cyl"), py::arg("Point"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Cylinder &, const Standard_Real>(), py::arg("Cyl"), py::arg("Dist"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Pnt &, const gp_Pnt &, const gp_Pnt &>(), py::arg("P1"), py::arg("P2"), py::arg("P3"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Ax1 &, const Standard_Real>(), py::arg("Axis"), py::arg("Radius"));
cls_GC_MakeCylindricalSurface.def(py::init<const gp_Circ &>(), py::arg("Circ"));

// Fields

// Methods
// cls_GC_MakeCylindricalSurface.def_static("operator new_", (void * (*)(size_t)) &GC_MakeCylindricalSurface::operator new, "None", py::arg("theSize"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete_", (void (*)(void *)) &GC_MakeCylindricalSurface::operator delete, "None", py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator new[]_", (void * (*)(size_t)) &GC_MakeCylindricalSurface::operator new[], "None", py::arg("theSize"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete[]_", (void (*)(void *)) &GC_MakeCylindricalSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GC_MakeCylindricalSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GC_MakeCylindricalSurface.def_static("operator delete_", (void (*)(void *, void *)) &GC_MakeCylindricalSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GC_MakeCylindricalSurface.def("Value", (const opencascade::handle<Geom_CylindricalSurface> & (GC_MakeCylindricalSurface::*)() const) &GC_MakeCylindricalSurface::Value, "Returns the constructed cylinder. Exceptions StdFail_NotDone if no cylinder is constructed.");

// Enums

}