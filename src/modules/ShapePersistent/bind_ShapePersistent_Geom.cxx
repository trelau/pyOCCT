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
#include <StdObjMgt_SharedObject.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <Standard_TypeDef.hxx>
#include <ShapePersistent_Geom.hxx>
#include <Geom_Geometry.hxx>
#include <Geom_CartesianPoint.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <Geom_Direction.hxx>
#include <gp_Dir.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <gp_Ax1.hxx>
#include <Geom_Axis1Placement.hxx>
#include <Geom_Axis2Placement.hxx>
#include <Geom_Transformation.hxx>
#include <gp_Trsf.hxx>
#include <Geom_Curve.hxx>
#include <Geom_Surface.hxx>
#include <Standard_Handle.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

void bind_ShapePersistent_Geom(py::module &mod){

/*
py::class_<ShapePersistent_Geom, std::unique_ptr<ShapePersistent_Geom>, StdObjMgt_SharedObject> cls_ShapePersistent_Geom(mod, "ShapePersistent_Geom", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Geom.def_static("Translate_", (opencascade::handle<Curve> (*)(const opencascade::handle<Geom_Curve> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom::Translate, "Create a persistent object for a curve", py::arg("theCurve"), py::arg("theMap"));
cls_ShapePersistent_Geom.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_Surface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom::Translate, "Create a persistent object for a curve", py::arg("theSurf"), py::arg("theMap"));

// Enums
*/

}