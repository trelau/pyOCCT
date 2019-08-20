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
#include <Standard_Transient.hxx>
#include <ShapePersistent_Poly.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <StdObjMgt_Persistent.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Poly_Polygon2D.hxx>
#include <ShapePersistent_HArray1.hxx>
#include <Poly_Polygon3D.hxx>
#include <StdLPersistent_HArray1.hxx>
#include <Poly_PolygonOnTriangulation.hxx>
#include <Poly_Triangulation.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>

void bind_ShapePersistent_Poly(py::module &mod){

/*
py::class_<ShapePersistent_Poly, std::unique_ptr<ShapePersistent_Poly>> cls_ShapePersistent_Poly(mod, "ShapePersistent_Poly", "None");

// Constructors

// Fields

// Methods
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Polygon2D> (*)(const opencascade::handle<Poly_Polygon2D> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a 2D polygon", py::arg("thePoly"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Polygon3D> (*)(const opencascade::handle<Poly_Polygon3D> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a 3D polygon", py::arg("thePoly"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<PolygonOnTriangulation> (*)(const opencascade::handle<Poly_PolygonOnTriangulation> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a triangulation", py::arg("thePolyOnTriang"), py::arg("theMap"));
cls_ShapePersistent_Poly.def_static("Translate_", (opencascade::handle<Triangulation> (*)(const opencascade::handle<Poly_Triangulation> &, StdObjMgt_TransientPersistentMap &)) &ShapePersistent_Poly::Translate, "Create a persistent object for a polygon on triangulation", py::arg("thePolyTriang"), py::arg("theMap"));

// Enums
*/

}