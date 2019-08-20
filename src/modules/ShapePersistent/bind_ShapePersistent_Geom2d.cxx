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
#include <ShapePersistent_Geom.hxx>
#include <Geom2d_Geometry.hxx>
#include <ShapePersistent_Geom2d.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Vec2d.hxx>
#include <Geom2d_Direction.hxx>
#include <gp_Dir2d.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <Geom2d_AxisPlacement.hxx>
#include <gp_Ax2d.hxx>
#include <StdObjMgt_SharedObject.hxx>
#include <Geom2d_Transformation.hxx>
#include <gp_Trsf2d.hxx>
#include <Geom2d_Curve.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

void bind_ShapePersistent_Geom2d(py::module &mod){

/*
py::class_<ShapePersistent_Geom2d, std::unique_ptr<ShapePersistent_Geom2d>> cls_ShapePersistent_Geom2d(mod, "ShapePersistent_Geom2d", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Geom2d.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom2d_Curve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom2d::Translate, "Create a persistent object for a curve", py::arg("theCurve"), py::arg("theMap"));

// Enums
*/

}