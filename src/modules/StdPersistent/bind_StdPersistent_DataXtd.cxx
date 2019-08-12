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
#include <StdLPersistent_Void.hxx>
#include <StdPersistent_DataXtd.hxx>
#include <TDataXtd_Shape.hxx>
#include <TDataXtd_Point.hxx>
#include <TDataXtd_Axis.hxx>
#include <TDataXtd_Plane.hxx>
#include <TDataXtd_Placement.hxx>
#include <StdObjMgt_Attribute.hxx>
#include <TDataXtd_Geometry.hxx>
#include <TDataXtd_Position.hxx>
#include <gp_Pnt.hxx>

void bind_StdPersistent_DataXtd(py::module &mod){

py::class_<StdPersistent_DataXtd, std::unique_ptr<StdPersistent_DataXtd, Deleter<StdPersistent_DataXtd>>> cls_StdPersistent_DataXtd(mod, "StdPersistent_DataXtd", "None");

// Constructors

// Fields

// Methods

// Enums

}