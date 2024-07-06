// This file is part of the Godot Orchestrator project.
//
// Copyright (c) 2023-present Vahera Studios LLC and its contributors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//		http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
#ifndef ORCHESTRATOR_PROPERTY_UTILS_H
#define ORCHESTRATOR_PROPERTY_UTILS_H

#include <godot_cpp/core/property_info.hpp>

namespace PropertyUtils
{
    using namespace godot;

    /// Checks whether the property type is <code>NIL</code>
    /// @param p_property the property to check
    /// @return true if the property is NIL, false otherwise
    _FORCE_INLINE_ bool is_nil(const PropertyInfo& p_property) { return p_property.type == Variant::NIL; }

    /// Checks whether the property represents a variant.
    /// @param p_property the property to check
    /// @return true if the property is a variant, false otherwise
    _FORCE_INLINE_ bool is_variant(const PropertyInfo& p_property) { return is_nil(p_property) && (p_property.usage & PROPERTY_USAGE_NIL_IS_VARIANT); }

    /// Checks whether the property represents a class type.
    /// @param p_property the property to check
    /// @return true if the property is a class type, false otherwise
    _FORCE_INLINE_ bool is_class(const PropertyInfo& p_property) { return p_property.type == Variant::OBJECT && !p_property.class_name.is_empty() && !p_property.class_name.contains("."); }

    /// Checks whether the property represents an enum.
    /// @param p_property the property to check
    /// @return true if the property is an enumeration, false otherwise
    _FORCE_INLINE_ bool is_enum(const PropertyInfo& p_property) { return p_property.hint == PROPERTY_HINT_ENUM || p_property.usage & PROPERTY_USAGE_CLASS_IS_ENUM; }

    /// Checks whether the property is a bitfield.
    /// @param p_property the property to check
    /// @return true if the property is a bitfield, false otherwise
    _FORCE_INLINE_ bool is_bitfield(const PropertyInfo& p_property) { return p_property.hint == PROPERTY_HINT_FLAGS || p_property.usage & PROPERTY_USAGE_CLASS_IS_BITFIELD; }

    /// Checks whether the property type is <code>NIL</code> but the variant flag is not set.
    /// @param p_property the property to check
    /// @return true if the property is <code>NIL</code> but has no variant flag set
    bool is_nil_no_variant(const PropertyInfo& p_property);

    /// Get the type name for the specified property
    /// @param p_property the property
    /// @return the property type name
    String get_property_type_name(const PropertyInfo& p_property);
}

#endif // ORCHESTRATOR_PROPERTY_UTILS_H