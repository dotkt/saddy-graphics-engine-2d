/*! \file getvalue.h

    Defines instantiations for pushing some values on stack of Duktape
 */
#pragma once
#include "basiccontext.h"
#include "../sadstring.h"
#include "../sadpoint.h"
#include "../classmetadatacontainer.h"
#include "../object.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "../db/save.h"
#include "../db/load.h"
 
namespace dukpp03
{

namespace internal
{

/*! Tries to get property with double value from object
    \param[in] ctx context
    \param[in] pos position of object in stack
    \param[in] propname a property name
    \return 
 */
::dukpp03::Maybe<double> tryGetDoubleProperty(
    sad::dukpp03::BasicContext* ctx, 
    duk_idx_t pos,
    const char* propname
);


/*! Tries to get property with int value from object
    \param[in] ctx context
    \param[in] pos position of object in stack
    \param[in] propname a property name
    \return 
 */
::dukpp03::Maybe<int> tryGetIntProperty(
    sad::dukpp03::BasicContext* ctx, 
    duk_idx_t pos,
    const char* propname
);
}

/*! An instantiation for getting constant char pointer
 */
template<>
class GetValue<const char*, sad::dukpp03::BasicContext>
{
public:
    /*! Performs getting value from stack 
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    static dukpp03::Maybe<const char*> perform(
        sad::dukpp03::BasicContext* ctx, 
        duk_idx_t pos
    );
};


/*! An instantiation for getting sad::String
 */
template<>
class GetValue<sad::String, sad::dukpp03::BasicContext>
{
public:
    /*! Performs getting value from stack 
        \param[in] ctx context
        \param[in] pos index for stack
        \return a value if it exists, otherwise empty maybe
     */
    static dukpp03::Maybe<sad::String> perform(
        sad::dukpp03::BasicContext* ctx, 
        duk_idx_t pos
    );
};


/*! An instantiation for sad::db::Object
 */
template<>
class GetValue<sad::db::Object*,  sad::dukpp03::BasicContext>
{
public:
/*! Performs getting value from stack
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static ::dukpp03::Maybe<sad::db::Object*> perform(
     sad::dukpp03::BasicContext* ctx,
    duk_idx_t pos
)
{
    ::dukpp03::Maybe<sad::db::Object*> result;
    if (duk_is_object(ctx->context(), pos))
    {
        duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx->context(), -1))
        {
            void* ptr = duk_to_pointer(ctx->context(), -1);
            sad::db::Variant * v = reinterpret_cast<sad::db::Variant *>(ptr);
            if (v->pointerStarsCount() == 1)
            {
                if (v->baseName() == "sad::db::Object") 
                {
                    result.setValue(v->get<sad::db::Object*>(true).value());
                } 
                else 
                {
                    if (sad::ClassMetaDataContainer::ref()->contains(v->baseName()))
                    {
                        bool created = false;
                        if (sad::ClassMetaDataContainer::ref()->get(v->baseName(), created)->canBeCastedTo("sad::Object"))
                        {
                            sad::Object** object = reinterpret_cast<sad::Object**>(v->data());
                            result.setValue(static_cast<sad::db::Object*>(*object));
                        }
                    }
                }
            }
        }
        duk_pop(ctx->context());
    }
    return result;
}

};



/*! An instantiation for sad::Object
 */
template<>
class GetValue<sad::Object*,  sad::dukpp03::BasicContext>
{
public:
/*! Performs getting value from stack
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static ::dukpp03::Maybe<sad::Object*> perform(
    sad::dukpp03::BasicContext* ctx,
    duk_idx_t pos
)
{
    ::dukpp03::Maybe<sad::Object*> result;
    if (duk_is_object(ctx->context(), pos))
    {
        duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx->context(), -1))
        {
            void* ptr = duk_to_pointer(ctx->context(), -1);
            sad::db::Variant * v = reinterpret_cast<sad::db::Variant *>(ptr);
            if (v->pointerStarsCount() == 1)
            {
                if (v->baseName() == "sad::Object") 
                {
                    result.setValue(v->get<sad::Object*>(true).value());
                } 
                else 
                {
                    if (v->baseName() == "sad::db::Object")
                    {
                        sad::db::Object* o = v->get<sad::db::Object*>(true).value();
                        sad::String real_name = o->serializableName();
                        bool created = false;
                        if (sad::ClassMetaDataContainer::ref()->contains(real_name))
                        {
                            bool created = false;
                            if (sad::ClassMetaDataContainer::ref()->get(real_name, created)->canBeCastedTo("sad::Object"))
                            {
                                sad::Object** object = reinterpret_cast<sad::Object**>(v->data());
                                result.setValue(*object);
                            }
                        }
                    }
                    else
                    {
                        if (sad::ClassMetaDataContainer::ref()->contains(v->baseName()))
                        {
                            bool created = false;
                            if (sad::ClassMetaDataContainer::ref()->get(v->baseName(), created)->canBeCastedTo("sad::Object"))
                            {
                                sad::Object** object = reinterpret_cast<sad::Object**>(v->data());
                                result.setValue(*object);
                            }
                        }
                    }
                }
            }
        }
        duk_pop(ctx->context());
    }
    return result;
}

};

/*! An instantiation for variant
 */
template<>
class GetValue<sad::db::Variant,  sad::dukpp03::BasicContext>
{
public:
/*! Performs getting value from stack
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static ::dukpp03::Maybe<sad::db::Variant> perform(
    sad::dukpp03::BasicContext* ctx,
    duk_idx_t pos
)
{
    ::dukpp03::Maybe<sad::db::Variant> result;
    if (duk_is_string(ctx->context(), pos))
    {
        result.setValue(sad::String(duk_to_string(ctx->context(), pos)));
    }
    if (duk_is_boolean(ctx->context(), pos))
    {
        result.setValue(static_cast<bool>(duk_to_string(ctx->context(), pos) != NULL));
    }
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(duk_to_number(ctx->context(), pos));
    }
    if (duk_is_object(ctx->context(), pos))
    {
        duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx->context(), -1))
        {
            void* ptr = duk_to_pointer(ctx->context(), -1);
            sad::db::Variant * v = reinterpret_cast<sad::db::Variant *>(ptr);
            if (v)
            {
                result.setValue(*v);
            }
        }
        duk_pop(ctx->context());
    }
    return result;
}

};



/*! An instantiation for sad::Point2D
 */
template<>
class GetValue<sad::Point2D,  sad::dukpp03::BasicContext>
{
public:
/*! Performs getting value from stack
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
inline static ::dukpp03::Maybe<sad::Point2D> perform(
    sad::dukpp03::BasicContext* ctx,
    duk_idx_t pos
)
{
    ::dukpp03::Maybe<sad::Point2D> result;
    ::dukpp03::internal::TryGetValueFromObject<sad::Point2D, sad::dukpp03::BasicContext>::perform(ctx, pos, result);
    if (result.exists() == false)
    {
        ::dukpp03::Maybe<sad::Point2D*> result2;
        ::dukpp03::internal::TryGetValueFromObject<sad::Point2D*, sad::dukpp03::BasicContext>::perform(ctx, pos, result2);
        if (result2.exists())
        {
            result.setReference(result2.value());
        }
        else
        {
            if (duk_is_object(ctx->context(), pos))
            {
                ::dukpp03::Maybe<double> maybex, maybey;
            }
        }
    }
    return result;
}

};

}