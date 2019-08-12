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
#include <StdLPersistent_HArray2.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_HArray2OfDir.hxx>
#include <TColgp_HArray2OfVec.hxx>
#include <TColgp_HArray2OfXY.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray2OfDir2d.hxx>
#include <TColgp_HArray2OfVec2d.hxx>
#include <TColgp_HArray2OfLin2d.hxx>
#include <TColgp_HArray2OfCirc2d.hxx>
#include <ShapePersistent_HArray2.hxx>

void bind_ShapePersistent_HArray2(py::module &mod){

py::class_<ShapePersistent_HArray2, std::unique_ptr<ShapePersistent_HArray2, Deleter<ShapePersistent_HArray2>>> cls_ShapePersistent_HArray2(mod, "ShapePersistent_HArray2", "None");

// Constructors

// Fields

// Methods

// Enums

}