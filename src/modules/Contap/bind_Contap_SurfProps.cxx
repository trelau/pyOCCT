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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Contap_SurfProps.hxx>

void bind_Contap_SurfProps(py::module &mod){

py::class_<Contap_SurfProps> cls_Contap_SurfProps(mod, "Contap_SurfProps", "Internal tool used to compute the normal and its derivatives.");

// Constructors

// Fields

// Methods
// cls_Contap_SurfProps.def_static("operator new_", (void * (*)(size_t)) &Contap_SurfProps::operator new, "None", py::arg("theSize"));
// cls_Contap_SurfProps.def_static("operator delete_", (void (*)(void *)) &Contap_SurfProps::operator delete, "None", py::arg("theAddress"));
// cls_Contap_SurfProps.def_static("operator new[]_", (void * (*)(size_t)) &Contap_SurfProps::operator new[], "None", py::arg("theSize"));
// cls_Contap_SurfProps.def_static("operator delete[]_", (void (*)(void *)) &Contap_SurfProps::operator delete[], "None", py::arg("theAddress"));
// cls_Contap_SurfProps.def_static("operator new_", (void * (*)(size_t, void *)) &Contap_SurfProps::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Contap_SurfProps.def_static("operator delete_", (void (*)(void *, void *)) &Contap_SurfProps::operator delete, "None", py::arg(""), py::arg(""));
cls_Contap_SurfProps.def_static("Normale_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &)) &Contap_SurfProps::Normale, "Computes the point <P>, and normal vector <N> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("N"));
cls_Contap_SurfProps.def_static("DerivAndNorm_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Contap_SurfProps::DerivAndNorm, "Computes the point <P>, and normal vector <N> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("d1u"), py::arg("d1v"), py::arg("N"));
cls_Contap_SurfProps.def_static("NormAndDn_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Real, const Standard_Real, gp_Pnt &, gp_Vec &, gp_Vec &, gp_Vec &)) &Contap_SurfProps::NormAndDn, "Computes the point <P>, normal vector <N>, and its derivatives <Dnu> and <Dnv> on <S> at parameters U,V.", py::arg("S"), py::arg("U"), py::arg("V"), py::arg("P"), py::arg("N"), py::arg("Dnu"), py::arg("Dnv"));

// Enums

}