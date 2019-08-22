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
#include <Prs3d_DimensionUnits.hxx>
#include <TCollection_AsciiString.hxx>

void bind_Prs3d_DimensionUnits(py::module &mod){

py::class_<Prs3d_DimensionUnits> cls_Prs3d_DimensionUnits(mod, "Prs3d_DimensionUnits", "This class provides units for two dimension groups: - lengthes (length, radius, diameter) - angles");

// Constructors
cls_Prs3d_DimensionUnits.def(py::init<>());
cls_Prs3d_DimensionUnits.def(py::init<const Prs3d_DimensionUnits &>(), py::arg("theUnits"));

// Fields

// Methods
cls_Prs3d_DimensionUnits.def("SetAngleUnits", (void (Prs3d_DimensionUnits::*)(const TCollection_AsciiString &)) &Prs3d_DimensionUnits::SetAngleUnits, "Sets angle units", py::arg("theUnits"));
cls_Prs3d_DimensionUnits.def("GetAngleUnits", (const TCollection_AsciiString & (Prs3d_DimensionUnits::*)() const) &Prs3d_DimensionUnits::GetAngleUnits, "Returns angle units");
cls_Prs3d_DimensionUnits.def("SetLengthUnits", (void (Prs3d_DimensionUnits::*)(const TCollection_AsciiString &)) &Prs3d_DimensionUnits::SetLengthUnits, "Sets length units", py::arg("theUnits"));
cls_Prs3d_DimensionUnits.def("GetLengthUnits", (const TCollection_AsciiString & (Prs3d_DimensionUnits::*)() const) &Prs3d_DimensionUnits::GetLengthUnits, "Returns length units");

// Enums

}