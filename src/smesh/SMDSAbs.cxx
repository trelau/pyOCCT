/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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

#include <SMDSAbs_ElementType.hxx>

PYBIND11_MODULE(SMDSAbs, mod) {

	// ENUMS
	py::enum_<SMDSAbs_ElementType>(mod, "SMDSAbs_ElementType", "//////////////////////////////////////////////////////////////////////////// Type (node, edge, face or volume) of elements ////////////////////////////////////////////////////////////////////////////")
		.value("SMDSAbs_All", SMDSAbs_ElementType::SMDSAbs_All)
		.value("SMDSAbs_Node", SMDSAbs_ElementType::SMDSAbs_Node)
		.value("SMDSAbs_Edge", SMDSAbs_ElementType::SMDSAbs_Edge)
		.value("SMDSAbs_Face", SMDSAbs_ElementType::SMDSAbs_Face)
		.value("SMDSAbs_Volume", SMDSAbs_ElementType::SMDSAbs_Volume)
		.value("SMDSAbs_0DElement", SMDSAbs_ElementType::SMDSAbs_0DElement)
		.value("SMDSAbs_Ball", SMDSAbs_ElementType::SMDSAbs_Ball)
		.value("SMDSAbs_NbElementTypes", SMDSAbs_ElementType::SMDSAbs_NbElementTypes)
		.export_values();

	py::enum_<SMDSAbs_GeometryType>(mod, "SMDSAbs_GeometryType", "enumeration for element geometry type")
		.value("SMDSGeom_POINT", SMDSAbs_GeometryType::SMDSGeom_POINT)
		.value("SMDSGeom_EDGE", SMDSAbs_GeometryType::SMDSGeom_EDGE)
		.value("SMDSGeom_TRIANGLE", SMDSAbs_GeometryType::SMDSGeom_TRIANGLE)
		.value("SMDSGeom_QUADRANGLE", SMDSAbs_GeometryType::SMDSGeom_QUADRANGLE)
		.value("SMDSGeom_POLYGON", SMDSAbs_GeometryType::SMDSGeom_POLYGON)
		.value("SMDSGeom_TETRA", SMDSAbs_GeometryType::SMDSGeom_TETRA)
		.value("SMDSGeom_PYRAMID", SMDSAbs_GeometryType::SMDSGeom_PYRAMID)
		.value("SMDSGeom_HEXA", SMDSAbs_GeometryType::SMDSGeom_HEXA)
		.value("SMDSGeom_PENTA", SMDSAbs_GeometryType::SMDSGeom_PENTA)
		.value("SMDSGeom_HEXAGONAL_PRISM", SMDSAbs_GeometryType::SMDSGeom_HEXAGONAL_PRISM)
		.value("SMDSGeom_POLYHEDRA", SMDSAbs_GeometryType::SMDSGeom_POLYHEDRA)
		.value("SMDSGeom_BALL", SMDSAbs_GeometryType::SMDSGeom_BALL)
		.value("SMDSGeom_NONE", SMDSAbs_GeometryType::SMDSGeom_NONE)
		.export_values();

	py::enum_<SMDSAbs_ElementOrder>(mod, "SMDSAbs_ElementOrder", "None")
		.value("ORDER_ANY", SMDSAbs_ElementOrder::ORDER_ANY)
		.value("ORDER_LINEAR", SMDSAbs_ElementOrder::ORDER_LINEAR)
		.value("ORDER_QUADRATIC", SMDSAbs_ElementOrder::ORDER_QUADRATIC)
		.export_values();

	py::enum_<SMDSAbs_EntityType>(mod, "SMDSAbs_EntityType", "Enumeration of entity type used in mesh info array")
		.value("SMDSEntity_Node", SMDSAbs_EntityType::SMDSEntity_Node)
		.value("SMDSEntity_0D", SMDSAbs_EntityType::SMDSEntity_0D)
		.value("SMDSEntity_Edge", SMDSAbs_EntityType::SMDSEntity_Edge)
		.value("SMDSEntity_Quad_Edge", SMDSAbs_EntityType::SMDSEntity_Quad_Edge)
		.value("SMDSEntity_Triangle", SMDSAbs_EntityType::SMDSEntity_Triangle)
		.value("SMDSEntity_Quad_Triangle", SMDSAbs_EntityType::SMDSEntity_Quad_Triangle)
		.value("SMDSEntity_BiQuad_Triangle", SMDSAbs_EntityType::SMDSEntity_BiQuad_Triangle)
		.value("SMDSEntity_Quadrangle", SMDSAbs_EntityType::SMDSEntity_Quadrangle)
		.value("SMDSEntity_Quad_Quadrangle", SMDSAbs_EntityType::SMDSEntity_Quad_Quadrangle)
		.value("SMDSEntity_BiQuad_Quadrangle", SMDSAbs_EntityType::SMDSEntity_BiQuad_Quadrangle)
		.value("SMDSEntity_Polygon", SMDSAbs_EntityType::SMDSEntity_Polygon)
		.value("SMDSEntity_Quad_Polygon", SMDSAbs_EntityType::SMDSEntity_Quad_Polygon)
		.value("SMDSEntity_Tetra", SMDSAbs_EntityType::SMDSEntity_Tetra)
		.value("SMDSEntity_Quad_Tetra", SMDSAbs_EntityType::SMDSEntity_Quad_Tetra)
		.value("SMDSEntity_Pyramid", SMDSAbs_EntityType::SMDSEntity_Pyramid)
		.value("SMDSEntity_Quad_Pyramid", SMDSAbs_EntityType::SMDSEntity_Quad_Pyramid)
		.value("SMDSEntity_Hexa", SMDSAbs_EntityType::SMDSEntity_Hexa)
		.value("SMDSEntity_Quad_Hexa", SMDSAbs_EntityType::SMDSEntity_Quad_Hexa)
		.value("SMDSEntity_TriQuad_Hexa", SMDSAbs_EntityType::SMDSEntity_TriQuad_Hexa)
		.value("SMDSEntity_Penta", SMDSAbs_EntityType::SMDSEntity_Penta)
		.value("SMDSEntity_Quad_Penta", SMDSAbs_EntityType::SMDSEntity_Quad_Penta)
		.value("SMDSEntity_Hexagonal_Prism", SMDSAbs_EntityType::SMDSEntity_Hexagonal_Prism)
		.value("SMDSEntity_Polyhedra", SMDSAbs_EntityType::SMDSEntity_Polyhedra)
		.value("SMDSEntity_Quad_Polyhedra", SMDSAbs_EntityType::SMDSEntity_Quad_Polyhedra)
		.value("SMDSEntity_Ball", SMDSAbs_EntityType::SMDSEntity_Ball)
		.value("SMDSEntity_Last", SMDSAbs_EntityType::SMDSEntity_Last)
		.export_values();

}
