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
#include <StdLPersistent_HArray1.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_HArray1OfDir2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_HArray1OfLin2d.hxx>
#include <TColgp_HArray1OfCirc2d.hxx>
#include <Poly_HArray1OfTriangle.hxx>
#include <ShapePersistent_HArray1.hxx>

void bind_ShapePersistent_HArray1(py::module &mod){

py::class_<ShapePersistent_HArray1, std::unique_ptr<ShapePersistent_HArray1>> cls_ShapePersistent_HArray1(mod, "ShapePersistent_HArray1", "None");

// Constructors

// Fields

// Methods

// Enums

}