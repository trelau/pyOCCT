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
#include <StdObjMgt_SharedObject.hxx>
#include <ShapePersistent_Geom_Surface.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_Handle.hxx>
#include <gp_Dir.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Surface.hxx>
#include <gp_Pnt.hxx>
#include <ShapePersistent_HArray2.hxx>
#include <StdLPersistent_HArray2.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <gp_Ax3.hxx>
#include <Geom_Plane.hxx>
#include <Geom_ConicalSurface.hxx>
#include <gp_Cone.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <gp_Cylinder.hxx>
#include <Geom_SphericalSurface.hxx>
#include <gp_Sphere.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <gp_Torus.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_OffsetSurface.hxx>

void bind_ShapePersistent_Geom_Surface(py::module &mod){

/*
py::class_<ShapePersistent_Geom_Surface> cls_ShapePersistent_Geom_Surface(mod, "ShapePersistent_Geom_Surface", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_Plane> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a plane", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_CylindricalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a cylinder", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_ConicalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a cone", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SphericalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a sphere", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_ToroidalSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a torus", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SurfaceOfLinearExtrusion> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a surface of linear extrusion", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_SurfaceOfRevolution> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a surface of evolution", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_BezierSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a Bezier surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_BSplineSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a BSpline surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_RectangularTrimmedSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for a rectangylar trimmed surface", py::arg("theSurf"), py::arg("theMap"));
cls_ShapePersistent_Geom_Surface.def_static("Translate_", (opencascade::handle<Surface> (*)(const opencascade::handle<Geom_OffsetSurface> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Geom_Surface::Translate, "Create a persistent object for an offset surface", py::arg("theSurf"), py::arg("theMap"));

// Enums
*/

}