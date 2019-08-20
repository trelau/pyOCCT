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
#include <Geom_Surface.hxx>
#include <Standard_OStream.hxx>
#include <Standard_IStream.hxx>
#include <Geom_Curve.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomTools_UndefinedTypeHandler.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomTools_SurfaceSet.hxx>
#include <GeomTools_CurveSet.hxx>
#include <GeomTools_Curve2dSet.hxx>
#include <GeomTools.hxx>

void bind_GeomTools(py::module &mod){

py::class_<GeomTools, std::unique_ptr<GeomTools>> cls_GeomTools(mod, "GeomTools", "The GeomTools package provides utilities for Geometry.");

// Constructors

// Fields

// Methods
// cls_GeomTools.def_static("operator new_", (void * (*)(size_t)) &GeomTools::operator new, "None", py::arg("theSize"));
// cls_GeomTools.def_static("operator delete_", (void (*)(void *)) &GeomTools::operator delete, "None", py::arg("theAddress"));
// cls_GeomTools.def_static("operator new[]_", (void * (*)(size_t)) &GeomTools::operator new[], "None", py::arg("theSize"));
// cls_GeomTools.def_static("operator delete[]_", (void (*)(void *)) &GeomTools::operator delete[], "None", py::arg("theAddress"));
// cls_GeomTools.def_static("operator new_", (void * (*)(size_t, void *)) &GeomTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomTools.def_static("operator delete_", (void (*)(void *, void *)) &GeomTools::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Dump, "A set of Curves from Geom2d. Dumps the surface on the stream.", py::arg("S"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Surface> &, Standard_OStream &)) &GeomTools::Write, "Writes the surface on the stream.", py::arg("S"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Surface> &, Standard_IStream &)) &GeomTools::Read, "Reads the surface from the stream.", py::arg("S"), py::arg("IS"));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
cls_GeomTools.def_static("Dump_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Dump, "Dumps the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Write_", (void (*)(const opencascade::handle<Geom2d_Curve> &, Standard_OStream &)) &GeomTools::Write, "Writes the Curve on the stream.", py::arg("C"), py::arg("OS"));
cls_GeomTools.def_static("Read_", (void (*)(opencascade::handle<Geom2d_Curve> &, Standard_IStream &)) &GeomTools::Read, "Reads the Curve from the stream.", py::arg("C"), py::arg("IS"));
cls_GeomTools.def_static("SetUndefinedTypeHandler_", (void (*)(const opencascade::handle<GeomTools_UndefinedTypeHandler> &)) &GeomTools::SetUndefinedTypeHandler, "None", py::arg("aHandler"));
cls_GeomTools.def_static("GetUndefinedTypeHandler_", (opencascade::handle<GeomTools_UndefinedTypeHandler> (*)()) &GeomTools::GetUndefinedTypeHandler, "None");
cls_GeomTools.def_static("GetReal_", [](Standard_IStream & IS, Standard_Real & theValue){ GeomTools::GetReal(IS, theValue); return theValue; }, "Reads the Standard_Real value from the stream. Zero is read in case of error", py::arg("IS"), py::arg("theValue"));

// Enums

}