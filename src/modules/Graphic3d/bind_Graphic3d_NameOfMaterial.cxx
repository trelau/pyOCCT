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
#include <Graphic3d_NameOfMaterial.hxx>

void bind_Graphic3d_NameOfMaterial(py::module &mod){

py::enum_<Graphic3d_NameOfMaterial>(mod, "Graphic3d_NameOfMaterial", "Types of aspect materials.")
	.value("Graphic3d_NOM_BRASS", Graphic3d_NameOfMaterial::Graphic3d_NOM_BRASS)
	.value("Graphic3d_NOM_BRONZE", Graphic3d_NameOfMaterial::Graphic3d_NOM_BRONZE)
	.value("Graphic3d_NOM_COPPER", Graphic3d_NameOfMaterial::Graphic3d_NOM_COPPER)
	.value("Graphic3d_NOM_GOLD", Graphic3d_NameOfMaterial::Graphic3d_NOM_GOLD)
	.value("Graphic3d_NOM_PEWTER", Graphic3d_NameOfMaterial::Graphic3d_NOM_PEWTER)
	.value("Graphic3d_NOM_PLASTER", Graphic3d_NameOfMaterial::Graphic3d_NOM_PLASTER)
	.value("Graphic3d_NOM_PLASTIC", Graphic3d_NameOfMaterial::Graphic3d_NOM_PLASTIC)
	.value("Graphic3d_NOM_SILVER", Graphic3d_NameOfMaterial::Graphic3d_NOM_SILVER)
	.value("Graphic3d_NOM_STEEL", Graphic3d_NameOfMaterial::Graphic3d_NOM_STEEL)
	.value("Graphic3d_NOM_STONE", Graphic3d_NameOfMaterial::Graphic3d_NOM_STONE)
	.value("Graphic3d_NOM_SHINY_PLASTIC", Graphic3d_NameOfMaterial::Graphic3d_NOM_SHINY_PLASTIC)
	.value("Graphic3d_NOM_SATIN", Graphic3d_NameOfMaterial::Graphic3d_NOM_SATIN)
	.value("Graphic3d_NOM_METALIZED", Graphic3d_NameOfMaterial::Graphic3d_NOM_METALIZED)
	.value("Graphic3d_NOM_NEON_GNC", Graphic3d_NameOfMaterial::Graphic3d_NOM_NEON_GNC)
	.value("Graphic3d_NOM_CHROME", Graphic3d_NameOfMaterial::Graphic3d_NOM_CHROME)
	.value("Graphic3d_NOM_ALUMINIUM", Graphic3d_NameOfMaterial::Graphic3d_NOM_ALUMINIUM)
	.value("Graphic3d_NOM_OBSIDIAN", Graphic3d_NameOfMaterial::Graphic3d_NOM_OBSIDIAN)
	.value("Graphic3d_NOM_NEON_PHC", Graphic3d_NameOfMaterial::Graphic3d_NOM_NEON_PHC)
	.value("Graphic3d_NOM_JADE", Graphic3d_NameOfMaterial::Graphic3d_NOM_JADE)
	.value("Graphic3d_NOM_CHARCOAL", Graphic3d_NameOfMaterial::Graphic3d_NOM_CHARCOAL)
	.value("Graphic3d_NOM_WATER", Graphic3d_NameOfMaterial::Graphic3d_NOM_WATER)
	.value("Graphic3d_NOM_GLASS", Graphic3d_NameOfMaterial::Graphic3d_NOM_GLASS)
	.value("Graphic3d_NOM_DIAMOND", Graphic3d_NameOfMaterial::Graphic3d_NOM_DIAMOND)
	.value("Graphic3d_NOM_TRANSPARENT", Graphic3d_NameOfMaterial::Graphic3d_NOM_TRANSPARENT)
	.value("Graphic3d_NOM_DEFAULT", Graphic3d_NameOfMaterial::Graphic3d_NOM_DEFAULT)
	.value("Graphic3d_NOM_UserDefined", Graphic3d_NameOfMaterial::Graphic3d_NOM_UserDefined)
	.export_values();


}